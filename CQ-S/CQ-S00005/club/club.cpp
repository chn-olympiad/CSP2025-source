#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
vector<int>club[4];
int cha[N],a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		long long ans=0;
		int cnt=0;
		for(int i=1;i<=3;i++)club[i].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int c1,c2,c3;
			scanf("%d%d%d",&c1,&c2,&c3);
			int maxx=max(c1,max(c2,c3));
			ans+=maxx; 
			if(maxx==c1){
				club[1].push_back(i);
				cha[i]=maxx-max(c2,c3);
			}
			else if(maxx==c2){
				club[2].push_back(i);
				cha[i]=maxx-max(c3,c1);
			}
			else{
				club[3].push_back(i);
				cha[i]=maxx-max(c1,c2);
			}
		}
		for(int i=1;i<=3;i++){
			if(club[i].size()>n/2){
				int w=club[i].size()-n/2;
				for(int j=0;j<club[i].size();j++){
					int u=club[i][j];
					a[++cnt]=cha[u];	
				}
				sort(a+1,a+1+cnt);
				
				for(int j=1;j<=w;j++){
					ans-=a[j];
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
