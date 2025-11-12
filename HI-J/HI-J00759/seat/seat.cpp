#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,s,w;
	int a[11][11],b[1001];
	cin>>n>>m;
	k=n*m;
	for(int i=0;i<k;i++)
	{
		cin>>b[i];
	}
	s=b[0];

	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(b[j]>b[i])
			swap(b[i],b[j]);
		 } 
	}
	
	for(int i=0;i<k;i++)
	{
		if(b[i]==s)
		{
			
			w=i+1;
			
		}
		
	}
	
	if(w<=n)
		cout<<"1"<<" "<<w;
	else if(w>n&&w<=2*n)
		cout<<"2"<<" "<<n-w+n+1;
	else if(w>2*n&&w<=3*n)
		cout<<"3"<<" "<<w-2*n;
	else if(w>3*n&&w<=4*n)
		cout<<"4"<<" "<<4*n-w+1;
	else if(w>4*n&&w<=5*n)
		cout<<"5"<<" "<<w-4*n;
	else if(w>5*n&&w<=6*n)
		cout<<"6"<<" "<<6*n-w+1;
	else if(w>6*n&&w<=7*n)
		cout<<"7"<<" "<<w-6*n;
	else if(w>7*n&&w<=8*n)
		cout<<"8"<<" "<<8*n-w+1;
	else if(w>8*n&&w<=9*n)
		cout<<"9"<<" "<<w-8*n;
	else if(w>9*n&&w<=10*n)
		cout<<"10"<<" "<<10*n-w+1;

	fclose(stdin);
	fclose(stdout);
}
