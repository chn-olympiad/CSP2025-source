#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		if(n==1){
			if(a[1]==k) cout<<1;
			else cout<<0;
			return 0;
		}
		if(n==2){
			if(a[1]==k&&a[2]==k) cout<<2;
			else if((a[1]==k&&a[2]!=k)||(a[2]==k&&a[1]!=k)||(a[1] xor a[2]==k)) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	int l[n+5],r[n+5];
	int x=0;
	int f[n+5][n+5]={-999};
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=a[i];
			for(int k=i+1;k<=j;k++){
				sum=sum xor a[k];
			}
			f[i][j]=sum;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[i][j]==k){
				l[++x]=i;
				r[x]=j;
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		cout<<l[i]<<' '<<r[i]<<endl;
	}
	*/
	int sum[n+5]={0};
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x;j++){
			if(r[i]<l[j]) sum[i]++;
		}
	}
	int ans=-999;
	for(int i=1;i<=n;i++){
		ans=max(ans,sum[i]);
	}
	cout<<ans<<endl;
}
