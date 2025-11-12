#include<bits/stdc++.h>
using namespace std;
struct l
{
	int fir=0;
	int sec=0;
};
bool ff(l a,l b)
{
	return a.sec>b.sec;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[t];
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
        l pm[3];
		for(int j=0;j<n[i];j++)
		{
			l a[3];
			cin>>a[0].sec>>a[1].sec>>a[2].sec;
			a[0].fir=0,a[1].fir=1,a[2].fir=2;
			sort(a,a+3,ff);
			if(pm[a[0].fir].fir<=n[i]/2)
			{
				pm[a[0].fir].fir++;
				pm[a[0].fir].sec+=a[0].sec;
			}
			else
			{
				if(pm[a[1].fir].fir<=n[i]/2)
				{
					pm[a[1].fir].fir++;
					pm[a[1].fir].sec+=a[1].sec;
				}
				else
				{
					pm[a[2].fir].fir++;
					pm[a[2].fir].sec+=a[2].sec;
				}
			}
		}
		cout<<pm[0].sec+pm[1].sec+pm[2].sec<<endl;
	}
	return 0;
}
