#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans=0;
bool check(int c,int s,int maxx){
	if(c>=3&&s>2*maxx){
		return true;
	}
	return false;
}
void f(int c,int s,int x,int maxx){
	if(check(c,s,maxx)){
		ans++;
	}
	for(int i=x;i<=n;i++){
		f(c+1,s+a[i],i+1,a[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	f(1,0,1,-1);
	cout<<ans%998244353;
	return 0;
} 
