#include<bits/stdc++.h>
using namespace std;

int n,m,a[101],ans,t=0,i=1,j=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n >> m;
	for(int g=1;g<=n*m;g++)
	  cin >> a[g];
	int f=a[1];
	sort(a+1,a+n*m+1);
	for(int g=n*m;g>=1;g--)
	  if(a[g]==f)
	  {
		  ans=n*m-g+1;
		  break;
	  }
	  while(1)
	    {
			if(i==n)
			{
			    for(int l=1;l<=n;l++)
			      {
					  i--;
					  t++;
					  if(t==ans)
					  {
						  
				  		 if(j>m)
				  		    cout << m << " " << i;
				  		 else if(i>n)
				  		    cout << j << " " << n;
				  		      else
				  		        cout << j << " " << i;
				  		  return 0;
					  }
				  }
		    }
			if(i==1)
			{
				for(int l=1;l<=n;l++)
			      {
					  i++;
					  t++;
					  if(t==ans)
					  {
						  
				  		 if(j>m)
				  		    cout << m << " " << i;
				  		 else if(i>n)
				  		    cout << j << " " << n;
				  		      else
				  		        cout << j << " " << i;
				  		  return 0;
					  }
				  }
			}
			else
			{
				      j++;
				      if(t==ans)
					  {
						  
				  		 if(j>m)
				  		    cout << m << " " << i;
				  		 else if(i>n)
				  		    cout << j << " " << n;
				  		      else
				  		        cout << j << " " << i;
				  		  return 0;
					  }
		        	  t++;
			}
		}

	return 0;
}
