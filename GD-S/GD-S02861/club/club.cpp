#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+100;
struct node{
	int num,who,where;
};
bool comp(node x,node y){
	return x.num>=y.num;
}
int t;
ll n,ans=0;
int a[N][4],clasn[10];
bool vis[N];
void dfs(int fl,int c1n,int c2n,int c3n,ll total){
	if(fl>n){
	//	cout<<c1n<<" "<<c2n<<" "<<c3n<<endl;
		ans=max(ans,total);
		return;
	}
	if(c1n< n/2){
		dfs(fl+1,c1n+1,c2n,c3n,total+a[fl][1]);
	}
	if(c2n< n/2){
		dfs(fl+1,c1n,c2n+1,c3n,total+a[fl][2]);
	}
	if(c3n< n/2){
		dfs(fl+1,c1n,c2n,c3n+1,total+a[fl][3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		vector<node> he;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			vis[i]=false;
//			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=1;j<=3;j++)
			{
				clasn[j]=0;
				cin>>a[i][j];
				he.push_back({a[i][j],i,j});
			}
		}// ‰»Î init
		if(n<30){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		} 
		sort(he.begin(),he.end(),comp);
//		for(int i=0;i<he.size();i++)
//		{
//			cout<<he[i].num<<" "<<he[i].who<<" "<<he[i].where<<" "<<endl;
//		}
		int len=he.size();
		for(int i=0;i<len;i++)
		{
			if(vis[he[i].who]) continue;
			if(clasn[he[i].where]>=(n/2)) continue;
			ans+=he[i].num;
			vis[he[i].who]=1;
			clasn[he[i].where]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/
