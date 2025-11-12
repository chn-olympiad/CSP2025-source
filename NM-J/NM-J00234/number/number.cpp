#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a,g,s,b;
    cin>>a;
    if(a/10==0)
    {
    	cout<<a;
	}
	else if(a/10<10)
	{
		s=a/10;
		g=a%10;
		if(g>s)
			cout<<g<<s;
		else
			cout<<s<<g;
	}
	else if(a/100<10)
	{
		s=a/10%10;
		g=a%100%10;
		b=a/100;
		if(g>s&&g>b&&s>b)
            cout<<g<<s<<b;
        else if(g>b&&s>g&&s>b)
            cout<<s<<g<<b;
        else if(g>b&&g>s&&s<b)
            cout<<g<<b<<s;
        else if(g<b&&s>g&&s>b)
            cout<<s<<b<<g;
        else if(g<b&&s<g&&s<b)
            cout<<b<<g<<s;
        else if(g<b&&s>g&&s<b)
            cout<<b<<s<<g;
	}
    return 0;
}
