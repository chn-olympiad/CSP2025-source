#include<bits/stdc++.h>
using namespace std;
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	long long a[m+2][m+2],b[m+2],c[m+2],s[m+2][m+2],d[k+2][n+3],d1[m+2];
	long long i=1,j;
	while(i<=m){
		b[i]=0;
		c[i]=0;
		d1[i]=0;
		i++;
	}
	i=0;
	while(i<=m){
		j=0;
		while(j<=m){
			a[i][j]=0;
			s[i][j]=0;
			j++;
		}
		i++;
	}
	long long t1,t2,t3;
	i=1;
	for(i=1;i<=m;i++)
	{
		cin>>t1>>t2>>t3;
		a[t1][t2]=1;
		b[t2]++;
		s[t1][t2]=t3;
	} 
	/*
	i=1;
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	i=1;
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	i=1;
	for(i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	i=1;
	for(i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	*/
	if(k>0){
		i=1;
		while(i<=k){
			j=1;
			while(j<=n+1){
				cin>>d[i][j];
				j++;
			}
			i++;
		}	
	}
	long long z=1,ans=0,x=0;
	if(k<=0)
	{
		i=1;
		while(x<m)
		{
			j=1;
			while(j<=m)
			{
				if(b[j]==0&&d1[i]==0)
				{
					x++;
					d1[i]=1;
					break;
				}
				j++;
			}
			z=1;
			while(z<=m)
			{
				if(a[j][z]==1&&c[z]==0)
				{
					c[z]=1;
					b[z]--;
					ans+=s[j][z];
				}
				z++;
			}
			i++;
		}	
	}
	cout<<ans;
	return 0;
}
