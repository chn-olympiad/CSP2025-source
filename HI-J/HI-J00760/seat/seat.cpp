#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],b[10010],r,seat[1010][1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	r=a[1];
	
	//降序排序b
	
	int ma=-1e9;
	for(int i=0;i<n*m;i++)
		{
			for(int j=i+1;j<=n*m;j++)
			{
				if(b[j]>ma)
				ma=j;
			}
			if(b[ma]>b[i])swap(b[i],b[ma]);
			ma=-1e9;
		} 
	
	if(r==ma) 
	{
		cout<<"1 1";
		return 0;
	} 
	int k=1;
	
	//入座 n行 m列  单数列从上往下 双数列从下往上 
	for(int i=1;i<=m;i++)//列 
	{
		if(i%2==1)//单数列 
		{
			for(int j=1;j<=n;j++)//从上往下 一列中的每一行 
			{
				seat[i][j]=b[k];
				k++;
			}
			k++;
			continue;
		}
		else if(i%2==0)//双数列 
		{
			for(int j=n;j>=1;j--)//从下往上 
			{
				seat[i][j]=b[k];
				k++;
			 } 
			 k++;
			 continue;
		 } 
	}
	
	//查找r的位置
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(seat[i][j]==r)
			cout<<i<<" "<<j;
		 } 
	 } 
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
