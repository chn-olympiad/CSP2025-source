#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k,sum;
int a[500005];
int pre[500005];

vector<int>Xor[500005];
int findnext(int x)
{
	int tgt=pre[x-1]^k;
	if(Xor[tgt].size()==0)return -1;
	if(Xor[tgt][Xor[tgt].size()-1]<x)return -1;
	int l=0,r=Xor[tgt].size()-1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(Xor[tgt][mid]>=x)r=mid;
		else l=mid+1;
	}
	//cout<<mid<<endl;
	return Xor[tgt][l];
 } 

signed main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		Xor[pre[i]].push_back(i);
	}
	int st=1;
	while(st<=n)
	{
		int ed=n+1;
		for(int i=st;i<=ed;i++)
		{
			int t=findnext(i);
			if(t<i)continue;
			if(t!=-1)
				ed=min(ed,t);
		}
		if(ed==n+1)break;
		st=ed+1;
		sum++;
	}
	cout<<sum;
	return 0;
}
