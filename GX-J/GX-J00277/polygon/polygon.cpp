#include<bits/stdc++.h>
using namespace std;
int c[5000];

int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b=0,g=0;
    cin>>a;
       if(a<3)
    {
		return 0;
	}
	for(int d=0;d<a;++d)
	{
		cin>>c[d];
		if(b<c[d])
		{
			b=c[d];
		}
    }
    for(int d=0;d<a;++d)
	{
		g=g+c[d];
		if(g<=b*2)
		{
			return 0;
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
