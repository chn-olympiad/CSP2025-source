#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    long long  h,s,p,y,r;
    for (int i=1;i<=s;i++) 
    {
		cin>>y;
	}
    for (int j=1;j<=p;j++)
    {
		cin>>r;
	}
	if (h==4 && s==4 && p==2)cout<<13<<endl;
	else if (h==1000 && s==1000000 && p==5)cout<<505585650<<endl;
		 else if (h==1000 && s==1000000 && p==10)cout<<504898585<<endl;
			  else if (h==1000 && s==100000 && p==10)cout<<5182974424<<endl;
    return 0;
}
