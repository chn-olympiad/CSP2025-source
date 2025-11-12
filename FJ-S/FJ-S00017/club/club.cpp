#include<bits/stdc++.h>
using namespace std;
int t,n,sum,ji[500005];
struct Node{
	vector<pair<int,int> > wt;
}e[500005];

bool cmd1(pair<int,int> a,pair<int,int> b) { return a.first>b.first; }
bool cmd2(int a,int b){
	if(e[a].wt[0].first-e[a].wt[1].first!=e[b].wt[0].first-e[b].wt[1].first) return e[a].wt[0].first-e[a].wt[1].first<e[b].wt[0].first-e[b].wt[1].first;
	else return e[a].wt[1].first-e[a].wt[2].first<e[b].wt[1].first-e[b].wt[2].first;
}
vector<int> bm[5];

void dfs(int j){
	if(bm[j].size()>n/2){
		sort(bm[j].begin(),bm[j].begin()+bm[j].size(),cmd2);
		int bx=bm[j][0];
		bm[j].erase(bm[j].begin());
		bm[e[bx].wt[ji[bx]+1].second].push_back(bx);
		sum-=e[bx].wt[ji[bx]].first-e[bx].wt[ji[bx]+1].first;
		ji[bx]++;
		dfs(e[bx].wt[ji[bx]].second);
	}
	else return;
}

int read(){
	int num=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		sum=0;
		n=read();
		for(int i=1;i<=n;i++){
			int x1=read(),x2=read(),x3=read();
			e[i].wt.push_back({x1,1});
			e[i].wt.push_back({x2,2});
			e[i].wt.push_back({x3,3});
			sort(e[i].wt.begin(),e[i].wt.begin()+3,cmd1);
		}
		for(int i=1;i<=n;i++){
			bm[e[i].wt[0].second].push_back(i);
			sum+=e[i].wt[0].first;
			dfs(e[i].wt[0].second);
		}
		cout<<sum<<"\n";
		for(int i=1;i<=n;i++) { e[i].wt.clear(); ji[i]=0; }
		for(int i=1;i<=3;i++) bm[i].clear();
	}
}
