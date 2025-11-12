//dfs
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;
int n,a[MAXN],ans;
set <vector<int>> st;
vector <int> v;
void dfs(int sta,int sum,int maxn)
{
	if(sta>n)return ;
	for(int i=sta;i<=n;i++)
	{
		v.push_back(i);
		if(sum+a[i]>(max(maxn,a[i])<<1))st.insert(v);
		dfs(i+1,sum+a[i],max(maxn,a[i]));
		v.pop_back();
	}
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	//qwq ovo awa
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dfs(i,0,0);
	cout<<st.size();
	return 0;
}
