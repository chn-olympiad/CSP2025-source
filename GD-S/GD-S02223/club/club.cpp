#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+10;
long long t;
long long a[6][mxn][4];
struct node{
	long long codd;
	long long d;
}chaa[6][mxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		long long n,bm1=0,bm2=0,bm3=0,ans=0;
		cin>>n;
		long long nn=n/2; 
			for(long long j=1;j<=n;j++){
				cin>>a[i][j][1]>>a[i][j][2]>>a[i][j][3];
				if(a[i][j][1]>=a[i][j][2]&&a[i][j][1]>=a[i][j][3]){
					bm1++;
					chaa[i][j].d=a[i][j][1]-max(a[i][j][2],a[i][j][3]);
					chaa[i][j].codd=1;
					ans+=a[i][j][1];
				}
				else if(a[i][j][2]>=a[i][j][1]&&a[i][j][2]>=a[i][j][3]){
					bm2++;
					chaa[i][j].d=a[i][j][2]-max(a[i][j][1],a[i][j][3]);
					chaa[i][j].codd=2;
					ans+=a[i][j][2];
				}
				else if(a[i][j][3]>=a[i][j][1]&&a[i][j][3]>=a[i][j][2]){
					bm3++;
					chaa[i][j].d=a[i][j][3]-max(a[i][j][2],a[i][j][1]);
					chaa[i][j].codd=3;
					ans+=a[i][j][3];
				}
				if(bm1>nn){
					long long minn=1e15;
					for(long long k=1;k<=j;k++){
						if(chaa[i][k].codd==1){
							minn=min(minn,chaa[i][k].d);
						}
					}
					for(long long k=1;k<=j;k++){
						if(chaa[i][k].codd==1&&chaa[i][k].d==minn){
							chaa[i][k].codd=0;
							break;
						}
					}
					if(chaa[i][j].d>minn){ 
						bm1--;
						ans-=minn;
					}
					else{
						bm1--;
						ans-=chaa[i][j].d;
					}
				}
				else
				if(bm2>nn){
					long long minn=1e15;
					for(long long k=1;k<=j;k++){
						if(chaa[i][k].codd==2){
							minn=min(minn,chaa[i][k].d);
							
						}
					}
					for(long long k=1;k<=j;k++){
						if(chaa[i][k].codd==2&&chaa[i][k].d==minn){
							chaa[i][k].codd=0;
							break;
						}
					}
					if(chaa[i][j].d>minn){ 
						bm2--;
						ans-=minn;
					}
					else{
						bm2--;
						ans-=chaa[i][j].d;
					}
				}
				else
				if(bm3>nn){
					long long minn=1e15;
					for(long long k=1;k<=j;k++){
						if(chaa[i][k].codd==3){
							minn=min(minn,chaa[i][k].d);
							
						}
					}
					for(long long k=3;k<=j;k++){
						if(chaa[i][k].codd==3&&chaa[i][k].d==minn){
							chaa[i][k].codd=0;
							break;
						}
					}
					if(chaa[i][j].d>minn){
						bm3--;
						ans-=minn;
					}
					else{
						bm3--;
						ans-=chaa[i][j].d;
					}
				}
			}
		cout<<ans<<endl;
	}
	return 0;
} 
