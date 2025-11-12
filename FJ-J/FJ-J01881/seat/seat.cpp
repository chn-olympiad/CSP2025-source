#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[114],st[11][11];
bool cmp(int a,int b){return a>b;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x,a[1]=x;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	int r=1,c=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x) break;
		if(r%2==1)
		{
			if(c==n) {r++;continue;}
			c++;
		}
		if(r%2==0)
		{
			if(c==1) {r++;continue;}
			c--;
		}
	}
	cout<<r<<' '<<c;
	return 0;
}
//rp++;

