#include<bits/stdc++.h>
using namespace std;
long long a[100000],c[100000],mod=998224353;
bool b[100000];
int n,ans;
void check(int s){
	int sum=0;
	for(int i=1;i<=s-2;i++){
		sum+=c[i];
	}
	if(sum>c[s-1]){
		ans++;
	}
	ans%=mod;
}
int f(int s,int sh,int g){
	if(s>g){
		check(s);
		return 0;
	}
	for(int i=sh+1;i<=n;i++){
		if(b[i]==false){
			c[s]=a[i];
			b[i]=true;
			f(s+1,i,g);
			b[i]=false;
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)f(1,0,i);
	cout<<ans%mod;
	return 0;
}
