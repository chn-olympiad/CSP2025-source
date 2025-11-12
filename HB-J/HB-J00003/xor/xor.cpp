#include <bits/stdc++.h>
using namespace std;

int a[500001];
struct node
{
	int start,end;
}num[500001];

bool cmp(node x,node y)
{
	return x.end<y.end;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,pos=1,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int len=1;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int sum=a[i];
			for(int j=i+1;j<=i+len-1;j++)
			{
				sum^=a[j];
			}
			if(sum==k)
			{
				num[pos].start=i;
				num[pos].end=i+len-1;
				pos++;
			}
		}
	}
	sort(num+1,num+pos,cmp);
	int now=0;
	for(int i=1;i<pos;i++)
	{
		if(num[i].start>now)
		{
			cnt++;
			now=num[i].end;
		}
	}
	cout<<cnt;
	return 0;
}