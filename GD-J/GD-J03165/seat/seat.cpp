#include <bits/stdc++.h>
using namespace std;
struct dd
{
	int ren;
	int fen;
};
dd s[1000006];
bool cmp(dd a,dd b)
{
	return a.fen>b.fen;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,h,l;
    cin>>h>>l;
    n=h*l;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].fen;
        s[i].ren=i;
	}
	sort(s+1,s+n+1,cmp);
	int x=2,y=1,f=0,t=0;
	int g=2;
	if(s[1].ren==1)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	n-=1;
	while(n)
    {	
    	if(s[g].ren==1)
    	{
    		cout<<y<<" "<<x<<endl;
    		return 0;
		}
		if(f==0)
		{
			if(x+1<=h)
			{
				x+=1;
			}
			else if(x+1>h)
			{
				y+=1;
				f=1;
				t=1;
			}
		}
		else if(f==1)
		{
			if(x-1>0)
			{
				x-=1;
			}
			else if(x-1<=0)
			{
				y+=1;
				f=0;
				t=1;
			}
		}
		n--;
		g++;
	}
	return 0;
}
