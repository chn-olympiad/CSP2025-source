#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int maxn;
int a[10];
int ans;
int tec;
struct str
{
	int s;
	int h;
};
int hs;
int my;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	str ty[10];
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ans=n;
		
		while(ans!=0)
		{
			int j=0;
			while(j<3)
			{
				cin>>ty[j].s;
				if(ty[j].s>maxn)
				{
					maxn = ty[j].s;
					hs = j;
					
				}
				j++;
			}
			cout<<hs;
			ty[hs].h++;
			if(ty[hs].h==n/2&&my<maxn)
			{
				tec = tec + maxn -my;
			}
			else tec+=maxn;
			maxn =0;
			j = 3;
			ans--;
			my = maxn;
			hs =0;
		}
		cout<<tec;
		tec = 0;
	}
	
	
	
	
	
	
	return 0;
}
