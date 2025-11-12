#include<bits/stdc++.h>
using namespace std;
long long n;
int c;
long long h;                  

long long club1[200005];
long long club2[200005];
long long club3[200005];
bool com(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("club.in","t",stdin);
	freopen("club.out","w",stdout);
	
	cin>>c;
	for(int i=0;i<c;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
        {
			
				cin>>club1[j];
				cin>>club2[j];
				cin>>club3[j];
		}
	    sort(club1+1,club1+1+n,com);
	    sort(club2+1,club2+1+n,com);
	    sort(club3+1,club3+1+n,com);
	    long long c1,c2,c3=0;
	    for(int i=1;i<=n;i++)
	    {
			if(club1[i]>club2[i]&&club1[i]>=club3[i])
			{
				if(c1<n/2)
				{
					h+=club1[i];
				    c1++;
				}
				else if(c2<2/n && club2[i]>=club3[i])
				{
					h+=club2[i];
					c2++;
				}
				else
				{
					h+=club3[i];
					c3++;
				}
			}
		    if (club2[i]>club3[i] && club2[i]>=club1[i])
			{
				if(c2<n/2)
				{
					h+=club2[i];
				    c2++;
				}
				else if(c1<2/n &&club1[i]>=club3[i])
				{
					h+=club1[i];
					c1++;
				}
				else
				{
					h+=club3[i];
					c3++;
				}
			}
			else if (club3[i]>club2[i] && club3[i]>=club1[i])
			{
				if(c3<n/2)
				{
					h+=club3[i];
				    c3++;
				}
				else if(c1<2/n && club1[i]>=club2[i])
				{
					h+=club1[i];
					c1++;
				}
				else
				{
					h+=club2[i];
					c2++;
				}
			}
			
		}
		cout<<h<<endl;
	}
	
    return 0;
}
