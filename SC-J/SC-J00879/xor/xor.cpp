#include<bits/stdc++.h>
using namespace std;
long long n,k,x,sum[500010],m,cnt;
vector<int>ll,rr;
bool st[500010],f;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum[i]=sum[i-1]^x;
	}
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			if((long long)(sum[l+len-1]^sum[l-1])==k)
			{
				ll.push_back(l);
				rr.push_back(l+len-1);
			}
		}
	}
	for(int i=0;i<ll.size();i++)
	{
		f=true;
		for(int j=ll[i];j<=rr[i];j++)
		{
			if(st[j])
			{
				f=false;
				break;
			}
		}
		if(f)
		{
			cnt++;
			for(int j=ll[i];j<=rr[i];j++)
			{
				st[j]=true;
			}
		}
	}
	cout<<cnt;
	return 0;
}
