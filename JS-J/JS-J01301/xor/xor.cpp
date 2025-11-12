#include<bits/stdc++.h>
using namespace std;
int n,m,a[500004],k,f[1003][1003],sum[500004];
int cnt;
bool flag,florr;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]!=1&&a[i]!=0){
			florr=1;
		}
	}
	if(flag==0&&florr==0){
		printf("%d",n/2);
	}
	else if(florr==0&&k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		printf("%d",ans);
	}
	else if(florr==0&&k==0){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt=0;
			}
			else if(a[i]==1){
				cnt^=1;
			}
			if(cnt==0){
				ans++;
			}
		}
		printf("%d",ans);
	}
	else{
		for(int i=1;i<=n;i++){
			f[i][i]=(a[i]==k);
		}
		for(int l=1;l<=n;l++){
			for(int i=1;i+l<=n;i++){
				int j=i+l;
				f[i][j]=((sum[j] xor sum[i-1])==k);
			//	cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
				for(int k=i;k<j;k++){
					f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
		}
		//for(int i=1;i<=n;i++){
		//	for(int j=i;j<=n;j++){
		//		cout<<f[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}
		printf("%d",f[1][n]);
	}
	return 0;
}
