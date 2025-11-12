#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+1000;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool flag=0;
	int a[N],f[N][256];
	//memset(f,0,sizeof f);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!flag && a[i]!=1)flag=1;
		if(a[i]<=k)f[i][a[i]]=1;
	}
	if(k==0 && !flag){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if((j^a[i])>=0){
				f[i][j]=max(f[i][j],f[i-1][j^a[i]]+f[i][j]);
			}
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++)ans=max(ans,f[i][k]);
	cout<<ans;
	return 0;
}
