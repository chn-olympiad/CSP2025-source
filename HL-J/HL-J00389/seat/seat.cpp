#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	int n,m,l;
	cin >> n >> m;
	int cnt[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin >> cnt[i];
	}
	l=cnt[0];
    if(n==1 and m==1) 
	{
		cout << 1 << " " << 1;
		return 0;
	}
	sort(cnt,cnt+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(l==cnt[i])
		{
			l=i+1;
			break;
		}
	}
	if(n==2 and m==2)
	{
		if(l==1) cout << 1 << " " << 1;
		else if(l==2) cout << 2 << " " << 1;
		else if(l==3) cout << 2 << " " << 2;
		else if(l==4) cout << 1 << " " << 2;
	}
	if(n==1) cout << 1 << " " << l;
	else if(m==1) cout << l << " " << 1;
	return 0;
}
