#inclube<bits/stdc++.h>
using namespace std;
int c[100000][4];
int y[100000],e[100000],s[100000],yl,el,sl;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		int b;
		cin>>b;
		for(int j=0;j<b;j++)
		{
			cin>>c[j][1]>>c[j][2]>>c[j][3];
		}
		int maxl=max(c[j][1],c[j][2]);
		maxl=max(maxl,c[j][3]);
		if(maxl==c[j][1])
		{
			y[yl]=maxl;
			yl++; 
		}
		else if(maxl==c[j][2])
		{
			e[el]=maxl;
			el++;
		}
		else(maxl==c[j][3])
		{ 
			s[sl]=maxl;
			sl++; 
		}
	}
	return 0;
}
