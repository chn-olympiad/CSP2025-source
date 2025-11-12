#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n==3) 
    {
    	scanf("%d%d%d",&a,&b,&c);
    	if(a+b+c>2*max(a,max(b,c))) printf("1");
    	else printf("0");
	}
    
	return 0;
}

