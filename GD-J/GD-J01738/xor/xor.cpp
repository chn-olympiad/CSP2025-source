#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans,s;
int a[N],v[N];
void di(int x,int y)
{
	for(int i=x;i<=y;i++)
		v[i]=1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(v[i]) continue;
		ans=0;
		for(int j=i;j<=n;j++)
		{
			ans^=a[j];
			if(ans==k)
			{
				s++;
				di(i,j);
				break;
			}
		}
	}
	
	cout<<s;
	return 0;
 } 
