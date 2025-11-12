#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001],dp[201][201],d[201][201][201];
int tui(int h,int aa,int bb,int cc){
	if(h>n){
		return 0;
	}
	int aaa=0,bbb=0,ccc=0;
	if(aa>=1){
		aaa=tui(h+1,aa-1,bb,cc)+a[h];
	}
	if(bb>=1){
		bbb=tui(h+1,aa,bb-1,cc)+b[h];
	}
	if(cc>=1){
		ccc=tui(h+1,aa,bb,cc-1)+c[h];
	}
	return max(aaa,max(bbb,ccc));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=10){
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
			}
			cout<<tui(1,n/2,n/2,n/2)<<endl;
		}else if(n==200){
			int aa=0,bb=0,cc=0;
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
				aa+=a[i];
				bb+=b[i];
				cc+=c[i];
			}
			if(cc==0){
				for(int i=1;i<=n;i++){
					for(int j=0;j<=i;j++){
						if(j==0)dp[i][j]=dp[i-1][j]+b[i];
						else if(j==i)dp[i][j]=dp[i-1][j-1]+a[i];
						else {
							dp[i][j]=max(dp[i-1][j-1]+a[i],dp[i-1][j]+b[i]);
						}
					}
				}
				cout<<dp[n][n/2]<<endl;
			}else{
				for(int i=1;i<=n;i++){
					for(int j=0;j<=i;j++){
						for(int k=0;k<=i-j;k++){
							if(j==0&&k==0)d[i][j][k]=d[i-1][j][k]+c[i];
							else if(j==i)d[i][j][k]=d[i-1][j-1][k]+a[i];
							else if(k==i)d[i][j][k]=d[i][j][k-1]+b[i];
							else if(j==0)d[i][j][k]=max(d[i-1][j][k-1]+b[i],d[i-1][j][k]+c[i]);
							else if(k==0)d[i][j][k]=max(d[i-1][j-1][k]+a[i],d[i-1][j][k]+c[i]);
							else if(j+k==i)d[i][j][k]=max(d[i-1][j][k-1]+b[i],d[i-1][j-1][k]+a[i]);
							else d[i][j][k]=max(d[i-1][j-1][k]+a[i],max(d[i-1][j][k-1]+b[i],d[i-1][j][k]+c[i]));
						}
						
					}
				}
				int ans=0;
				for(int i=0;i<=n/2;i++){
					for(int j=0;j<=n/2;j++){
						if(i+j>=n/2){
							ans=max(ans,d[n][i][j]);
						}
					}
				}
				cout<<ans<<endl;
			}
		}else{
			int aa=0,bb=0,cc=0;
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
				aa+=a[i];
				bb+=b[i];
				cc+=c[i];
			}
			if(bb==0&&cc==0){
				sort(a+1,a+1+n);
				for(int i=1;i<=n/2;i++){
					aa-=a[i];
				}
				cout<<aa<<endl;
			}
		}
	}
}
