#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct node
{
	int x,y,z;
}a[maxn];
int ans;
int t,n;
void dfs(int w,int bm1,int bm2,int bm3,int sum)
{
	if(w>=n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(bm1+1<=n/2)
		dfs(w+1,bm1+1,bm2,bm3,sum+a[w].x);
	if(bm2+1<=n/2)
		dfs(w+1,bm1,bm2+1,bm3,sum+a[w].y);
	if(bm3+1<=n/2)
		dfs(w+1,bm1,bm2,bm3+1,sum+a[w].z);
	return;
}
int main_()
{
	vector<int>bm[5]={};
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	dfs(1,0,0,0,0);
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
		cout<<main_()<<endl;
	return 0;
}
/*

呜呜呜，只会这一道题，还只是暴力思路呜呜呜

┭┮﹏┭┮ 

*/
