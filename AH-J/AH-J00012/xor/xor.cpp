#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,a,b[100][22],nn[100],s[100],z;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		nn[i]=0;
		while(a>0)
		{
			if(i>0)
			{
				if(a%2==1)
				{
					if(b[i-1][nn[i]]==0)
					{
						b[i][nn[i]]=1;
					}else{
						b[i][nn[i]]=0;
					}
				}else{
					if(b[i-1][nn[i]]==1)
					{
						b[i][nn[i]]=1;
					}else{
						b[i][nn[i]]=0;
					}
				}
			}else{
				if(a%2==1)
				{
					b[i][nn[i]]=1;
				}else{
					b[i][nn[i]]=0;
				}
			}
			a/=2;
			nn[i]++; 	
		cout<<b[i][nn[i]];
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		z=1;
		while(nn[i]>=0)
		{
			if(b[i][nn[i]]==1)
			{
				s[i]+=z;
			}
			z*=2;
			nn[i]--;
		} 
		cout<<s[i]<<' ';
	}
	return 0;
}
