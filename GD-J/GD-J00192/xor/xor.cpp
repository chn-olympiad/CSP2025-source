#include<bits/stdc++.h>
using namespace std;
int n,k,num,a;
bool f=true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    if(k==0){
    	for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a);
    	if(a!=1) f=false;
	}
	  if(f) printf("%d",n/2);
	}
    else if(k==1) 
    {
    	num=n;
    	for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a);
    	if(a!=1) num--;
	}
	    printf("%d",num);
	}
	return 0;
}

