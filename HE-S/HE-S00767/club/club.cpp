#include<bits/stdc++.h>
using namespace std;
int t,n,g[200][200],m[200];
struct node{
	int maxn,maxnn;
}a[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	a[0].maxn=-100;
	a[0].maxnn=-1000;	
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int sum=0;
			memset(g,0,sizeof(g));
			memset(m,0,sizeof(m));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>g[i][j];
				}
				if(g[i][1]==0&&g[i][2]==0&&g[i][3]!=0&&g[i][3]>a[i-1].maxn){
					a[i].maxn=g[i][3];
					a[i-1].maxn=0;
					m[3]=1;
				}else if(g[i][1]==0&&g[i][2]!=0&&g[i][3]==0&&g[i][2]>a[i-1].maxn){
					a[i].maxn=g[i][2];
					a[i-1].maxn=0;
					m[2]=1;			
				}else if(g[i][1]!=0&&g[i][2]==0&&g[i][3]==0&&g[i][1]>a[i-1].maxn){
					a[i].maxn=g[i][1];
					a[i-1].maxn=0;
					m[1]=1;			
				}else if(g[i][1]!=0&&g[i][2]!=0&&g[i][3]!=0){
					int maxnnn=0,maxni;
					for(int o=1;o<=3;o++){
						if(maxnnn<=g[i][o]&&m[i]==0){
							maxnnn=g[i][o];
							a[i].maxnn=a[i].maxn;
							a[i].maxn=g[i][o];
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				sum+=a[i].maxn;
			}
			cout<<sum<<endl;
		}else{
			memset(g,0,sizeof(g));
			memset(m,0,sizeof(m));
			int maxnn=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>g[i][j];
				}
			}
			for(int i=1;i<=n;i++){
				maxnn=max(maxnn,g[i][1]);
			}
			cout<<maxnn<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
