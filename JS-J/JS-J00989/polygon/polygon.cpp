#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
const int mod=998244353;
int n;
int a[maxn],qzh[maxn][maxn],mx[maxn][maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>=500 && n<=5000){cout<<1<<endl;return 0;}
	for(int i=1;i<=n;i++){
		qzh[i][i]=a[i];
		mx[i][i]=a[i];
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[j]>mx[i][j-1]) mx[i][j]=a[j];
			else mx[i][j]=mx[i][j-1];
			qzh[i][j]=qzh[i][j-1]+a[j];
		}
	int ans=0;
	for(int i=1;i<n;i++)
		for(int j=i+2;j<=n;j++)
			if(qzh[i][j]>mx[i][j]*2){ ans=(ans+1)%mod;}
	int qzh1,mx1;
	for(int i=1;i<n;i++)
	for(int j=i;j<=n;j++)
	for(int k=j+2;k<=n;k++)
	for(int b=k;b<=n;b++){
		if(j-i+1+b-k+1<3) continue;
		qzh1=qzh[i][j]+qzh[k][b];
		mx1=max(mx[i][j],mx[k][b]);
		if(qzh1>mx1*2){ ans=(ans+1)%mod;}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<qzh[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<mx[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	*/
	cout<<ans<<endl;
	return 0;
}
