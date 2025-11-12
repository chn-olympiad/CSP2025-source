#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//Ren5Jie4Di4Ling5%	`
	long long t,n,a[10000],b[10000],c[10000],maxn=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i])maxn+=a[i];
			else if(b[i]>a[i]&&b[i]>c[i])maxn+=b[i];
			else maxn+=c[i];
		}
		cout<<maxn;
	}
	
}
/*
 * 3
 * 4
 * 4 2 1
 * 3 2 4
 * 5 3 4
 * 3 5 1 
 *   
 * 
 * */
