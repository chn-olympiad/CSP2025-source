#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int num[N];
int k;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>num[i];
		if(i==1)
			k=num[i];
		num[i]=-num[i];
	}
	sort(num+1,num+n*m+1);
	for(int i=1;i<=n*m;i++)
		num[i]=-num[i];
	int l=1,r=1,id=1;
	while(1<=l&&l<=m&&1<=r&&r<=n)
	{
		if(num[id]==k)
		{
			cout<<l<<" "<<r<<"\n";
			return 0;
		} 
		if((r==n&&l%2==1)||(r==1&&l%2==0))
			l++;
		else
		{
			if(l%2==1)
				r++;
			else
				r--;
		}
		id++;
	} 
	return 0;
} 