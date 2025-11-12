#include<bits/stdc++.h>
using namespace std;
int a[101],r,w;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			w=i;
			break;
		}
	}
	int l=(w-1)/n+1;
	if(l%2) cout<<l<<" "<<(w-1)%n+1;
	else cout<<l<<" "<<n-(w-1)%n;
	return 0;
}
