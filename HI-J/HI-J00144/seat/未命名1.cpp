#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m,R,q1,q2;
	cin>>n>>m;
	int sum[m][n];
	int po[m*n];
	for(int i=1;i<=m*n;i++)
	{
		cin>>po[i];
		if(i==1)
		{
			R=i;
		}
	}
	int t=m*n;
	sort(po+1,po+t+1);
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=n;i++)
		{
			sum[k][i]=po[t];
			t--;					
		}
		k++;		
		for(int j=n;j==1;j--)
		{
			sum[k][j]=po[t];
			t--;
		}		
	}

	for(int l=1;l<=n;l++)	
	{
		for(int o=1;o<=m;o++)
		{
			if(sum[o][l]==R);
			{
				if(o<=10&&l<=10)
				q1=o;
				q2=l;				
			
			}	
		
	
		}
	}
	cout<<q1<<" "<<q2;

	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
