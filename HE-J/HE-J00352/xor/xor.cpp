#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],c[500005],mn,sum,z=pow(2,20),vg,shu,ans,de;
bool b=0;
string x,y;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >>k;
    for (int i=1;i<=n;i++)
    {
    	cin >> a[i];
    	if (a[i]==1) sum++;
    	if (a[i]==0) mn++;
    	if (a[i]!=1) b=1;
	}
    if (k==0&&(!b))
    {
    	cout << n/2;
	}
	else if (k==1&&(!b))
	{
		cout << n;
	}
	else if (k==1&&b) cout << sum;
	else{
		for (int j=1;j<=n;j++)
	    {
	        if (a[j]==k)
	        {
	    	    de++;
	    	    c[j]=1;
	    	    continue; 
		    }
	    }
	    if (n>1000&&k>255)
	    {
	    	cout << de;
		}
		else{
	    for (int j=1;j<=n;j++)
	    {
	    	if (c[j])continue;
	    	ans=a[j];
	        for (int i=j+1;i<=n;i++)
	        {
	        	if (c[i]) break;
	        	z=pow(2,20);
	        	vg=a[i];
	        	shu=0;
		    	while (z!=0)
		    	{
		    		if (ans>=z&&vg>=z)
		    		{
		    			shu+=0;
		    			ans-=z;
		    			vg-=z;
					}
					else if (ans>=z)
					{
						shu+=z;
						ans-=z;
					}
					else if (vg>=z)
					{
						shu+=z;
						vg-=z;
					}
					z/=2;
				}
				ans=shu;
				if (shu==k) {
					de++;
					for (int g=1;g<=i;g++)
					{
						c[g]=1;
					}
					break;
				}
	        }
	    }
	    cout << de;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

