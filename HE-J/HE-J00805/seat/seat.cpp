//rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100001];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
	int rp=n*m;
	int temp;
	for(int i=1;i<=rp;i++) cin>>a[i];
	temp=a[1];
	sort(a+1,a+rp+1,cmp);
	int ggg;
	for(int i=1;i<=rp;i++)
	{
		if(a[i]==temp)
		{
			ggg=i;
			break;
		}
	}
	int ls,hs;
	ls=ggg/n;
	if(ggg%n!=0)
	{
		ls++;
	}
	if(ls%2!=0)
	{
		hs=ggg%n;
		if(hs==0)
		{
			hs=n;
		}
	}
	else
	{
		hs=n-(ggg%n)+1;
		if(hs>n)
		{
			hs=n;
		}
	}
	cout<<ls<<" "<<hs;
	return 0;
}
//rp++
