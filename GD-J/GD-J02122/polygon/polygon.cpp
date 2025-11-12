#include<iostream>
using namespace std;
int n,a[11],s,xz[11];
bool b[11];
void dfs(int nn,int k)
{
	if(nn==0)
	{
		int sum=0,ma=0;
		for(int i=1;i<=k;i++)
		{ 
			sum+=a[xz[i]];
			ma=max(a[xz[i]],ma);
		}
		if(ma*2<sum) s++,s%=998244353;
		//for(int i=1;i<=k;i++) cout<<xz[i]<<" ";
		//cout<<"  "<<s<<endl;
	}
	else
	{
		for(int i=xz[k]+1;i<=n;i++)
		{
			if(b[i]) continue;
			b[i]=true;
			xz[k+1]=i;
			dfs(nn-1,k+1);
			b[i]=false;
			xz[k+1]=0;
		}
	}
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
	for(int i=3;i<=n;i++)
	{
		dfs(i,0);
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
