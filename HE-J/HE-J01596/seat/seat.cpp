#include<bits/stdc++.h>
using namespace std;
const int N=15;

int n,m;
int a[N][N];
struct Node{
	int score;
	bool R;
}s[105];
bool fla=1;

void dfs(int x,int y,int p,bool r){
	if(!fla)return;
	a[x][y]=s[p].score;
	if(s[p].R&&fla){
		cout<<x<<" "<<y;
		fla=0;
		return;
	}
	if(y==n&&(!r))dfs(x+1,y,p+1,1);
	if(y==1&&r)	  dfs(x+1,y,p+1,0);
	if(r)dfs(x,y-1,p+1,r);
	else dfs(x,y+1,p+1,r);
	return ;
}
bool cmp(Node a,Node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].score;
		if(i==1)s[i].R=1;
	}
	sort(s+1,s+n*m+1,cmp);
	dfs(1,1,1,0);
	return 0;
}
