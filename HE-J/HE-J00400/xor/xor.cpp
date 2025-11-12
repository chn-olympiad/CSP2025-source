#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int n,k,l,r,cnt;
vector<int>num;
bool is[50005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		num.push_back(tmp);
	}
	if(k==0)
	{
		cout<<1;
		return 0;
	}
	int temp;
	for(;l<=n;l++)
	{
		r=0;
		for(;r<=n;r++)
		{
			temp=0;
			for(int i=l;i<=r;i++)
			{
			 	temp^=num[i];
			}
			if(temp==k)
			{
				if(is[temp])
					continue;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
