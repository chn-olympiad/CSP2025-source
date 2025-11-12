#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}w[500005];
int n,q,k,a[500005],pre[500005],ans;
vector<int>re[500005];
bool flag[500005];
bool cmp(node f,node l)
{
	return f.r<l.r;
}
int binery(int x,int num)
{
	int l=0,r=re[num].size()-1;
	if(l==r)
	{
		return re[num][0]-1;
	}
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(re[num][mid]<x)
		{
			l=mid+1;
		}
		else 
		{
			r=mid;
		}
	}
	
	return re[num][l-1];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>q;
	re[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		re[pre[i]].push_back(i);
		flag[pre[i]]=1;
	}
//	for(int i=0;i<=n;i++)
//	{
//		cout<<i<<":";
//		for(int j=0;j<re[i].size();j++)
//		{
//			cout<<re[i][j]<<"  ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	pre[r]^pre[l-1]=q;
	int index=0;
	for(int i=1;i<=n;i++)
	{
		int p=pre[i]^q;
		if(flag[p]==1)
		{
			int bin=binery(i,p);
			if(bin==-1||bin==i)
			{
				continue;
			}
			index++;
			w[index]={bin+1,i};
//			cout<<i<<"  "<<p<<" "<<binery(i,p)<<"  "<<endl;
			
		}
	}
	sort(w+1,w+index+1,cmp);
//	for(int i=1;i<=index;i++)
//	{
//		cout<<w[i].l<<" "<<w[i].r<<endl;
//	}
	int last=0;
	for(int i=1;i<=index;i++)
	{
		if(w[i].l>last)
		{
			last=w[i].r;
			ans++;
		}
		
	}
	cout<<ans;
	return 0;
}
