#include<bits/stdc++.h>
using namespace std;
int d[100][100];
int e[100];

int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int a,b,c,f,h,m=1,o=1;
	cin>>a>>b;
	c=a*b;
	for(int d=1;d<=c;++d)
	{
		cin>>e[d];
     }
     f=e[1];
     for(int k=1;k<=c;++k)
     {
		 h=e[k];
		 if(f<h)
		 {
			 ++m;
			 }
  }
          if(m<a)
		{
				 cout<<1<<" "<<m;
				 return 0;
		}
		else
		{
			for(;m>a;)
			{
				m=m-a;
				o++;
			}
		 }
	 cout<<o<<" "<<m;
	 fclose(stdin);
     fclose(stdout);
	 return 0;
}
