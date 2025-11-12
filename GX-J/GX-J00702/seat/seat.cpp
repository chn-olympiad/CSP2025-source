#include<iostream>
using namespace std;
int main()
{
	int a,b,c,n,m,x,z,y,i=1;
	cin>>n>>m;
	int d[n*m];
	if(i<n*m)
    {
	cin>>d[i];
	i++;
    }
    i=0;
	c=d[1];
	while(i=n*m)
	{
		x=d[1];
		if(x<d[i+1])
        {
            z=d[i=1];
		d[i+1]=x;
		d[i]=z;
		y++;
		i++;
        if(x<=d[i+1])
            {
            i++;
            }
        }
	}
	a==(d[y]%4);
	b==(d[y]/4);
	cout<<b<<" "<<a;
	return 0;
}
