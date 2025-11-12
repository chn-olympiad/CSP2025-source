#include<iostream>

using namespace std;

int main()
{
    int m,n,a,b=0,c=0,r=0;

	cin>>m;

	cin>>n;
	a=m*n;

    int x[1000];


    for(int i=0;i<a;++i)
    {
        cin>>x[i];
    }


    for(int i=0;i<=a;++i)
    {
        if(x[i]>=x[0])
        {
            b+=1;
        }
    }
    c=b/m +1;
    if(c%2==0)
    {
        r = 2 * m - b + 1;
    }
        else
        {
            r=b%m;
        }

    cout<<c<<" "<<r;

    return 0;
}
