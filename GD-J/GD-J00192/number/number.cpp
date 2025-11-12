#include<bits/stdc++.h>
using namespace std;
char a;
int n[1000005],sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&a)!=EOF)
	{
		if(a>='0'&&a <='9') 
	  {
	  	n[sum]=(int)(a)-48;
	  	sum++;
	  }
	}  
	sort(n,n+sum);
	for(int i=sum-1;i>=0;i--) printf("%d",n[i]);
	return 0;
}

