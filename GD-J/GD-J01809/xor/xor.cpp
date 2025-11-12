#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n,k;
int sum=0;
int a[N];
int ans=0;
struct node{
	int l,r;
}v[N];
struct nnode{
	int vis;
	vector<int>w;
}vv[N];
struct kslf{
	int id,numm;
}num[N];
bool cmp(kslf a,kslf b)
{
	return a.numm>b.numm;
}
void dfs()
{
	for(int i=1;i<=n;i++)
	{
		int summ=0;
		for(int j=i;j<=n;j++)
		{
			summ^=a[j];
			if(summ==k)
			{
				vv[sum].vis=0;
				v[++sum]={i,j};
//				cout<<i<<" "<<j<<" "<<summ<<endl;
			}
		}
	}
	return;
}
void work()
{
	int p=0;
	for(int i=1;i<=sum;i++)
		for(int j=i+1;j<=sum;j++)
		{
			if(v[i].r>=v[j].l)
			{
				vv[i].w.push_back(j);
				vv[j].w.push_back(i);
				num[i].id=i;num[i].numm++;
				num[j].id=j;num[j].numm++;
			}
		}
		
	sort(num+1,num+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		if(num[i].numm==0)
		{
			ans=sum-i+1;
			return;
		}
		num[i].numm=5e5+10;
		for(int j=0;j<vv[num[i].id].w.size();j++)
		{
			num[vv[num[i].id].w[j]].numm--;
		}
		sort(num+1,num+sum+1,cmp);
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs();
	work();
	cout<<ans;
	return 0;
} 
