#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ccmp(int a,int b)
{
	return a > b;
}
int a[1001];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+(n*m),ccmp);
	int i=0,j=1,bian=1,num=0;
	while (1)
	{
		if (bian==1)
			{
			i++;
			if (i==n+1)i--,bian++,j++;
			}
		else if (bian==2)
			{
			i--;
			if (i==0)i++,bian--,j++;
			}
		num++;
		if (a[num]==r)
			break;
	}
	cout<<j<<' '<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

