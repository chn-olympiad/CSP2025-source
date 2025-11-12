#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int t,n,a[maxn],c[maxn],ans=0,b[maxn],k[maxn][maxn/2];
void gc()
{
	for(int h=1;h<4;h ++){
	for(int i=1;i<=n/2;i ++){
		for(int j=1;j<=n;j ++){
			if(h==1) k[i][j]=max(k[i][j],k[i-1][j]+a[j]);
			else if(h==2) k[i][j]=max(k[i][j],k[i-1][j]+b[j]);
			else k[i][j]=max(k[i][j],k[i-1][j]+c[j]);
		}
	}
   }
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    int l=0;
    while(t--){
    	cin >> n;
    	for(int i=1;i<=n;i ++) cin >> a[i]>>b[i]>>c[i];
    	if(b[1]==0&&c[1]==0){
    		sort(a+1,a+1+n);
		for(int i=n;i>=1;i --){
		 ans+=a[i],l++;
		 if(l+1>n/2){
		 	cout << ans;
		 }
	}
}
    else {
    	gc();
    	cout <<k[n/2][n]*2;
	} 
    	memset(k,0,sizeof(a)),memset(b,0,sizeof(b)),ans=0,l=0;
	}
	return 0;
 }
