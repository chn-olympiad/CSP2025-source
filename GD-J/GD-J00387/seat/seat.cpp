#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int n,m,r,c;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
		if(a[i]==t)
		{
			r=i/n,c=i%n;
			if(c!=0) r++;
			else c=n;
			if(r&1) break;
			else
			{
				c=n+1-c;
				break;
			}
		}
	cout<<r<<" "<<c;
	return 0;
}
