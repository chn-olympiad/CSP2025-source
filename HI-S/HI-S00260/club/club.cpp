#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N][4],d[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int b[4];
		int s=0;
		for(int i=1;i<=n;i++)
		{
			int z=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			z=max(a[i][1],max(a[i][2],a[i][3]));
			d[i]=z;
			for(int j=1;j<=3;j++)
			{
				if(z==a[i][j])
				{
					a[i][0]=j;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[a[i][0]]<n/2){
				s+=a[i][a[i][0]];
				b[a[i][0]]++;
			}
			else{
				a[i][a[i][0]]=-1;
				int z=0;
				z=max(a[i][1],max(a[i][2],a[i][3]));
				for(int j=1;j<=3;j++)
				{
					if(z==a[i][j]&&b[j]<n/2)
					{
						a[i][0]=j;
						b[a[i][0]]++;
						s+=a[i][a[i][0]]; 
						break;
					}
				}
				
			}
		}
		cout<<s<<"\n"; 
	}
	
	
	return 0;
}
