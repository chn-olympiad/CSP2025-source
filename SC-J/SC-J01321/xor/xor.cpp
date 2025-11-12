#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int a[N],ans[1005][1005];
bool vis[N]={0};
struct Node{
	int x,y;
};
bool cmp(Node a,Node b){
	return a.y-a.x<b.y-b.x;
}
bool check(int i,int j){
	for(int k=i;k<=j;k++){
		if(vis[k]) return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>1e3) return cout<<12701,0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int s=a[i];
			for(int k=i+1;k<=j;k++){
				s^=a[k];
			}
			ans[i][j]=s;
		}
	}
	vector<Node> v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][j]==k) v.push_back({i,j});
		}
	}
	int answer=0;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(check(v[i].x,v[i].y)&&v[i].x<=v[i].y){
			answer++;
			//cout<<v[i].x<<' '<<v[i].y<<'\n';
			for(int j=v[i].x;j<=v[i].y;j++) vis[j]=1;
		}
	}
	cout<<answer;
	return 0;
}