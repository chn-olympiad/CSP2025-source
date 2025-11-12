#include<iostream>
using namespace std;
int a[500001],b[500001];
int n,k,ans;
int dfs(int r,int l)
{
	if(r<l||r>n||l<1) return 0;
	for(int i=l;i<=r;i++)
	{
		for(int j=i;j<=r;j++)
			if((a[j]^a[i-1])==k)
			{
				return 1+dfs(i-1,l)+dfs(r,j+1);
			}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
    	a[i]=b[i]^a[i-1];
	}
	cout<<dfs(n,1);
	return 0;
} 
//beng huai xing qiong tie dao 118496512
 
