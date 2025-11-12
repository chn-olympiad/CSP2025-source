#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=1e4+10;
int a[MAXN][3],n;

int dfs(int i,int ca,int cb,int cc)
{
	if(i>n)return 0;
	int ret=0;
	if(ca<n/2)ret=max(ret,a[i][1]+dfs(i+1,ca+1,cb,cc));
	if(cb<n/2)ret=max(ret,a[i][2]+dfs(i+1,ca,cb+1,cc));
	if(cc<n/2)ret=max(ret,a[i][3]+dfs(i+1,ca,cb,cc+1));
	return ret;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	cout<<dfs(1,0,0,0)<<'\n';
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)solve();
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
	

