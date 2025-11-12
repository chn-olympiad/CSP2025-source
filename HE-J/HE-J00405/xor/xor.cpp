#include<bits/stdc++.h>
using namespace std;
int v[500010],top,ans;
struct abc
{
	int x,y;
}l[500010];
bool cmp(abc a,abc b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x>b.x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>v[i],v[i]^=v[i-1];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((v[j]^v[i-1])==k)
			{
				++top,l[top].x=i,l[top].y=j;
				break;
			}
	sort(l+1,l+top+1,cmp);
	int lt=0;
	for(int i=1;i<=top;i++)
	{
		if(lt<l[i].x)
			ans++,lt=l[i].y;
	}
	cout<<ans<<endl;
	return 0;
}
