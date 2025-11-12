#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char s[10];
    cin >> s;
    int a,b,d,e,f,g,h,i,j,k;
	for(int i=1;i<=10;i++)
    {
        if(s[1]>s[0])
        {
   	        a = s[0];
     	    s[0]=s[1];
     		s[1]=a;
		}
	}
	for(int i=1;i<=10;i++)
    {
        if(s[2]>s[1])
        {
   	        b = s[1];
     	    s[1]=s[2];
     		s[2]=b;
		}
	}
	for(int i=1;i<=10;i++)
    {
        if(s[3]>s[2])
        {
   	        d = s[2];
     	    s[2]=s[3];
     		s[3]=d;
		}
	}
	for(int i=1;i<=10;i++)
    {
        if(s[4]>s[3])
        {
   	        e = s[3];
     	    s[3]=s[4];
     		s[4]=e;
		}
	}
	for(int i=1;i<=10;i++)
    {
        if(s[5]>s[4])
        {
   	        f = s[4];
     	    s[4]=s[5];
     		s[5]=f;
		}
	}
	for(int i=1;i<=10;i++)
    {
        if(s[6]>s[5])
        {
   	        g = s[5];
     	    s[5]=s[6];
     		s[6]=g;
		}
	}
	for(int i=1;i<=10;i++)
    {
        if(s[7]>s[6])
        {
   	        h = s[6];
     	    s[6]=s[7];
     		s[7]=h;
		}
	}
	for(int i=1;i<=10;i++)
    {
        if(s[8]>s[7])
        {
   	        i = s[7];
     	    s[7]=s[8];
     		s[8]=i;
		}
	}
	cout << s;
    return 0;
}
