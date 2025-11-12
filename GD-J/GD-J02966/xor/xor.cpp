#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+100;
int n,k;
int a[MAXN];
int b[MAXN];
bitset<MAXN> use;
bool check(int x,int len)
{
	for (int i=x;i<=x+len-1;i++)
	{
		if (use[i]) return false;
	}
	for (int i=x;i<=x+len-1;i++)
	{
		use[i]=true;
	}
	return true;
}
int sum;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	int ans=0;
	for (int len=1;len<=n;len++)
	{
		if (len==1)
		{
			for (int i=1;i<=n;i++)
			{
				if (a[i]==k)
				{
					ans++;
					use[i]=true;
				}
			}
		}
		else
		{
			for (int x=1;x+len-1<=n;x++)
			{
//				cout<<x<<" "<<x+len-1<<" "<<(b[x+len-1]^b[x])<<endl;
				if ((b[x+len-1]^b[x-1])==k)
				{
					if (check(x,len))
					{
//						cout<<x+1<<" "<<x+len-1<<endl;
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
8 2
1 2 3 4 5 6 7 8

zhe dao ti gun qu hui shou zhan ba sb 
si huo bzd wei shen me yang li 5 cha 1
me:68
answer:69
???
*/
