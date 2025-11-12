#include <iostream>
#include <set>
using namespace std;
const int N=5010;
int a[N];int n;
int ans;
int lg[N];
int pw[15];
//struct node
//{
//	int a,b,c;
//	const bool operator<(const *rhs)const
//	{
//		return false;
//	}
//};
//set<node> vis;
void dfs(int x,int mx,int sm)
{
//	node temp;
//	temp={x,mx,sm};
//	if(vis.count(temp))
//	{
//		return;
//	}
	//cout<<x<<'\n';
	if(x==n+1)
	{
		if(sm>2*mx)
		{
			ans++;
			
		}return;
	}
	//ѡ
	dfs(x+1,max(mx,a[x]),sm+a[x]);
	dfs(x+1,mx,sm);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	dfs(1,0,0);
	cout<<ans<<'\n';
	
	return 0;
}
