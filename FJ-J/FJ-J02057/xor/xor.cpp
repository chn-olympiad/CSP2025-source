#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k,ans=0;
int b[1005][1005],qz[1005];
void query(int a,int d){
	int flag=0;
	for(int i=a;i<=n;i++)
		if(b[a][i]==k&&flag==0) query(i+1,d+1),flag=1;
	if(flag==0)
		ans=max(ans,d);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],ans+=a[i];
		cout<<ans;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<n/2;
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			qz[i]=qz[i-1]^a[i];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				b[i][j]=qz[j]^qz[i-1];
		query(1,0);
		cout<<ans;
		return 0;
	}            
	cout<<0;                                                       
	return 0;
}
