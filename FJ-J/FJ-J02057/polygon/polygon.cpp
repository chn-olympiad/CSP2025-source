#include<bits/stdc++.h>
using namespace std;
int a[5005],qz[5005],flag[5005];
int mod=998244353,ans=0;int n;
void query(int g,int b,int c,int d){
	c++;
	if(c==g){
		for(int i=b+1;i<=n;i++)
			if(flag[i]==0&&a[i]<d) ans++; 
		return;
	}
	else{
		for(int i=b+1;i<=n;i++){
			if(flag[i]==0){
				flag[i]=1;
				query(g,i,c,d+a[i]);
				flag[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	if(qz[n]==n){
		int x=1;
		for(int i=1;i<=n;i++)
			x=x*2%mod;
		x=x-n-1-n*(n-1)/2;
		if(x<0)
			cout<<x+mod;
		else
			cout<<x;
		return 0;
	}
	for(int i=3;i<=n;i++)
		query(i,0,0,0);
	cout<<ans%mod;
	return 0;
}
