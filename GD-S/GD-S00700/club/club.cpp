# include<bits/stdc++.h>
using namespace std;
struct Node{long long x,y,z;}peps[100005];
long long ans,T,n;
vector<long long>Node[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,ans=0,Node[0].clear(),Node[1].clear(),Node[2].clear();
		for(int i = 1;i<=n;i++){
			cin>>peps[i].x>>peps[i].y>>peps[i].z;
			ans+=max({peps[i].x,peps[i].y,peps[i].z});
		    if(peps[i].x>=peps[i].y&&peps[i].x>=peps[i].z)Node[0].push_back(peps[i].x-max(peps[i].y,peps[i].z));
	else 	if(peps[i].y>=peps[i].x&&peps[i].y>=peps[i].z)Node[1].push_back(peps[i].y-max(peps[i].x,peps[i].z));
	else 	if(peps[i].z>=peps[i].x&&peps[i].z>=peps[i].y)Node[2].push_back(peps[i].z-max(peps[i].x,peps[i].y));
		}
		for(int i = 0;i<3;i++){
			sort(Node[i].begin(),Node[i].end());	
			for(int j = 0;j<(int)Node[i].size()-n/2;j++)ans-=Node[i][j];
		}
		cout<<ans<<"\n";
	}
}
