#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char a[1000005];
int b[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int k=0;
    while(cin>>a[k])
    {
		if(a[k]>='0'&&a[k]<='9')
		{
			b[(int)a[k]]++;
	    }
	    k++;
	}
		
    for(int i=9;i>=0;i--)
    {
        while(b[i]!=0)
        {
            cout<<i;
            b[i]--;
        }
    }
    return 0;
}
