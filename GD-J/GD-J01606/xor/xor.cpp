#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1145141],b[1145141],l[1145141],r[1145141],bx,ans,jj,yoyo=1,dyb;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				if(a[i]==m&&b[i]==0){
					ans++;
					b[i]=yoyo;
					l[yoyo]=i;
					r[yoyo]=i;
					yoyo++;
					break;
				}
			}
			else{
				bx=a[i];
				for(int k=i+1;k<=j;k++){
					bx=(bx^a[k]);
					if(b[k]!=0){
						jj=1;
						dyb=b[k];
					}
				}
				if(bx==m&&jj==0){
					for(int k=i;k<=j;k++) b[k]=yoyo;
					l[yoyo]=i;
					r[yoyo]=j;
					yoyo++;
					ans++;
					break;
				}
				else if(bx==m&&jj==1){
					if(j-i<r[dyb]-l[dyb]){
						for(int k=l[dyb];k<=r[dyb];k++) b[k]=0;
						for(int k=i;k<=j;k++) b[k]=dyb;
						l[dyb]=i;
						r[dyb]=j;
						jj=0;
						break;
					}
				}
				jj=0;
			}
		}
	}
	cout<<ans;
}
