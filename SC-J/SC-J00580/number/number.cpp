#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("nubmer1.in","r",stdin);
    freopen("nubmer.out","w",stdout);
    char a[0];
    char b[0];
    int c=0;
    cin>>a;
	
    while(int i=1)
	{
        if(a[i]==0||1||2||3||4||5||6||7||8||9)
        {
            b[i]=a[i];
        }
        for(int j=i;j<=i;j++)
    {
    	if(b[j]<b[j+1])
    	{
    		c=b[j];
			b[j]=b[j+1];
			b[j+1]=c;
			
		}
		
	}
	break;		
    }
	cout<<b[c];
    return 0;

 
}