#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,M=1e3+10;
int n,k,a[N],m[M][M];
struct node
{
	int l,r;
};
vector<node> s;
bool st[M];
int maxn=-1;
void dfs(int r,int num,int len)
{
	if(num==len+1)return;
	
	for(int i=1;i<=len;i++)
	{
		if(!st[i] && s[i].l > r)
		{
			st[i]=1;
			dfs(s[i].r,num+1,len);
			st[i]=0;
		}
		maxn=max(maxn,num);
	}
} 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<=n;l++)
	{
		m[l][l]=a[l];
		if(m[l][l] == k)s.push_back({l,l});
		for(int r=l+1;r<=n;r++)
		{
			m[l][r] = m[l][r-1]^a[r];
			if(m[l][r] == k)s.push_back({l,r});
		}
	}
	int len=s.size();
	if(len==1)maxn=max(1,maxn);
	dfs(0,0,len);//×îÓÒ¶Ë£¬¸öÊý 
	cout<<maxn;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3
*/

