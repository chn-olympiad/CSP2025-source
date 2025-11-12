//GZ-S00114   遵义市第十二中学   唐小杰 
#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int i,j,k,l;
	int t,r,m[10001][3],max_love[3]={0,0,0},max_last_love[3]={0,0,0},love[3]={0,0,0};
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>r;
		for(j=0;j<r;j++)
		{
			for(k=0;k<3;k++)
			{
				cin>>m[j][k];
				for(l=0;l<r;l++)
				{
					max_love[k]=max(max_love[k-1],m[j][k]);
					max_last_love[k]=min(max_love[k-1],max_love[k-2]);
				}
				
				love[k]+=max_love[k];
			}	
	    }
		love[k]+=max_last_love[k];
		cout<<love[k];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);

}

