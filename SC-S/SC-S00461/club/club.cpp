#include<bits/stdc++.h>
using namespace std;
struct node{
	int idx,myd;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		vector<node> a,b,c;
		int n;cin>>n;
		int G[100005][3],ans[100005],A=0,B=0,C=0,visited[100005]={0};
		for(int j=1;j<=n;j++){
			cin>>G[j][0]>>G[j][1]>>G[j][2];
			ans[j]=max(max(G[j][0],G[j][1]),G[j][2]);
			if(ans[j]==G[j][0]){
				A++;
				a.push_back({j,ans[j]});
			}
			else if(ans[j]==G[j][1])B++,b.push_back({j,ans[j]});
			else{C++;c.push_back({j,ans[j]});}
	    }
		while(A>n/2||B>n/2||C>n/2){
			vector<node> minn(n,{0,-1});
			int ans1,ans2,ans3=-1;
			if(A>n/2){
				for(node it:a){
					if(it.myd==minn[0].myd){
						minn.push_back({it.idx,it.myd});
					}
					else if(it.myd<minn[0].myd){
						minn.clear();
						minn.push_back({it.idx,it.myd});
					}
					else{
						break;
					}
				}
				for(node it:minn){
					if(ans3<G[it.idx][1]&&!visited[it.idx]){
						ans3=G[it.idx][1];
						ans1=it.idx;
						ans2=1;
					}
					if(ans3<G[it.idx][2]&&!visited[it.idx]){
						ans3=G[it.idx][2];
						ans1=it.idx;
						ans2=2;
					}
				}
				if(ans2==1){b.push_back({ans1,ans3});B++;}
				else{c.push_back({ans1,ans3});C++;}
				A--;visited[ans1]=1; 
			}
			else if(B>n/2){
				for(node it:b){
					if(it.myd==minn[1].myd&&!visited[it.idx]){
						minn.push_back({it.idx,it.myd});
					}
					else if(it.myd<minn[1].myd&&!visited[it.idx]){
						minn.clear();
						minn.push_back({it.idx,it.myd});
					}
					else{
						break;
					}
				}
				for(node it:minn){
					if(ans3<G[it.idx][0]){
						ans3=G[it.idx][0];
						ans1=it.idx;
						ans2=0;
					}
					if(ans3<G[it.idx][2]){
						ans3=G[it.idx][2];
						ans1=it.idx;
						ans2=2;
					}
				}
				if(ans2==0){a.push_back({ans1,ans3});A++;}
				else{c.push_back({ans1,ans3});C++;}
				B--;visited[ans1]=1;                     
			}
			else{ 
				for(node it:c){
					if(it.myd==minn[2].myd&&!visited[it.idx]){
						minn.push_back({it.idx,it.myd});
					}
					else if(it.myd<minn[2].myd&&!visited[it.idx]){
						minn.clear();
						minn.push_back({it.idx,it.myd});
					}
					else{
						break;
					}
				}
				for(node it:minn){
					if(ans3<G[it.idx][0]){
						ans3=G[it.idx][0];
						ans1=it.idx;
						ans2=0;
					}
					if(ans3<G[it.idx][1]){
						ans3=G[it.idx][1];
						ans1=it.idx;
						ans2=1;
					}
				}
				if(ans2==0){a.push_back({ans1,ans3});A++;}
				else{b.push_back({ans1,ans3});B++;}
				C--;visited[ans1]=1;                       
			}
			ans[ans1]=ans3;
		}
		for(int j=2;j<=n;j++){
			ans[j]+=ans[j-1];
		}
		cout<<ans[n]<<"\n";
	}
	return 0;
}