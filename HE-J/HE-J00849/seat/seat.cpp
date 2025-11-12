#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);std::cin.tie(0);
	int n,m,l,o=0;
	std::cin>>n>>m;
	int a[m*n+1],b[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		std::cin>>a[i];
	}
	if(n==1 and m==1)
	{
		std::cout<<a[1];
		return 0;
	}
	l=a[1];
	std::sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		++o;
		b[o]=a[i];
	}

	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==l)
		{
			if(i%n==0)
			{
				cout<<i/n<<" ";
			}
			else
			{
				cout<<i/n+1<<" ";
			}
			if(i<=n)
			{
				cout<<i;
			}
			else
			{
				int p=0,uo=0;
				bool uu=true;
				while(uo<i)
				{
					if(uu==false)
					{
						p--;
					}
					if(uu==false and p==1)
					{
						uo+=2;
						uu=true;
						if(uo==i)
						{
							break;
						}
					}
					uo++;
					if(uu==true)
						p++;
					if(uo==i)
					{
						break;
					}
					if(p==n)
					{
						uo++;
						if(uo==i)
						{
							break;
						}
						uu=false;
					}
				}
				cout<<p;
	    	} 
	    	break;
		}
		
	}
	return 0;
}//Óñ»Ê´óµÛ±£ÓÓ 
//10:17
