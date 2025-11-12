#include<bits/stdc++.h>
using namespace std;
const int modd=998244353;
int a[5100],remem[5100];
int ans=0,n;
bool cmp(int a1a,int b1b){
	return a1a<b1b;
}
void mathing(){
	int maxn=0,sum=0;
	for(int i=1;i<=n;i++){
		if(remem[i]==1){
			sum+=a[i];
			maxn=max(maxn,a[i]); 
		}
	}
	if(sum>2*maxn){
		ans++;
		ans%=modd;
	}
}
void check(int i){
	if(i==n+1){
		mathing();
		return;
	}
	remem[i]=0;
	check(i+1);
	remem[i]=1;
	check(i+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	check(1);
	cout<<ans;
	return 0;
}
