#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int N,n,sum=0,aa[100005],bb[100005],cc[100005],a=0,b=0,c=0;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
	    cin>>n;
	    for(int i=1;i<=n;i++)
	    {
	    	int ne,num;
		    cin>>aa[i];
		    cin>>bb[i];
		    cin>>cc[i];
		    int x=max(aa[i],max(bb[i],cc[i]));
		    int m=min(aa[i],min(bb[i],cc[i]));
		    int w=aa[i]+bb[i]+cc[i]-x-m;
		    if(x==aa[i])
		    {
			   	if(a>(n/2))
			   	{
			   		sum+=w;
			   		if(w==bb[i])
			   		{
			   			b++;
					}
					else{
						c++;
					}
				}
				else{
					sum+=x;
					a++;
				}
			}
			else if(x==bb[i])
			{
				if(b>(n/2))
			    {
			    	sum+=w;
					if(w==aa[i])
					{
						a++;
						}	
					else{
						c++;
					}
				}
				else{
					sum+=x;
					b++;
				}
			}
			if(x==cc[i])
			{
			    if(c>(n/2))
			    {
			    	sum+=w;
			    	if(w==aa[i])
			    	{
			    		a++;
					}
					else{
						b++;
					}
				}
				else{
					sum+=x;
					c++;
				}
		    }
		    
	    }
	    cout<<sum<<endl;
	    sum=0;
	    a=0,b=0,c=0;
    }
	return 0;
}
