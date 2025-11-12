#include<bits/stdc++.h>
#define max_n 105
using namespace std;
int n,m;
int a[max_n];
int anum=0;
int ft=0;
int ft_i=0;
int ans_k=0; 
int ans_t=0; 
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    anum=n*m;
    for(int i=1;i<=anum;i++)
    {
    	cin>>a[i];
	}
	ft=a[1];
	sort(a+1,a+1+anum,cmp);
	for(int i=1;i<=anum;i++)
	{
		if(a[i]==ft)
		{
			ft_i=i;
			break;
		}
	}
	int lft=ft_i%n;
	if(lft==0)
	{
		ans_k=ft_i/n;
		if(ans_k%2==0)
		{
			cout<<ans_k<<" "<<"1";
			return 0;
		}
		if(ans_k%2==1)
		{
			cout<<ans_k<<" "<<n;
			return 0;
		}
	} 
	else
	{
		ans_k=(ft_i-lft)/n+1;
		if(ans_k%2==0)
    	{
	    	ans_t=(n-lft)+1;
	    	cout<<ans_k<<" "<<ans_t;
	    	return 0;
    	}
    	if(ans_k%2==1)
    	{
     		ans_t=lft;
	    	cout<<ans_k<<" "<<ans_t;
    		return 0;
    	}
	}
	return 0;
}
