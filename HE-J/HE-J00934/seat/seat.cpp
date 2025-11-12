#include<bits/stdc++.h>
using namespace std;
struct score
{
	int s;
	bool r;
};
bool cmp(score a,score b)
{
	return a.s>b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	score x[n*m+1]={};
	cin>>x[1].s;
	x[1].r=true;
	for(int i=2;i<=n*m;i++)
	{
		cin>>x[i].s;
	}
	sort(x+1,x+n*m+1,cmp);
	int xx=1,yy=1,f=1;
	for(int i=1;i<=n*m;)
	{
		xx+=f;
		i++;
		if(x[i].r==true)
		{
			cout<<yy<<' '<<xx;
			break;
		}
		if(xx==n&&f==1||xx==1&&f==-1)
		{
			yy++;
			i++;
			f=-f;
			if(x[i].r==true)
			{
				cout<<yy<<' '<<xx;
				break;
			}
		}
	}
	fclose(stdin);fclose(stdout);
}
