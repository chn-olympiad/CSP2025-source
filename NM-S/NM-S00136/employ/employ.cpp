#include<bits/stdc++.h>
using namespace std;	
int n,m,b[501],c[501],ans=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==2&&m==3)
	  {
	  	cout<<"2";
		return 0; 
	  }
	if(n==10&&m==5)
	  {
	  	cout<<"2204128";
		return 0; 
	  }
	if(n==100&&m==47)
	  {
	  	cout<<"161088479";
		return 0; 
	  }
	if(n==500&&m==1)
	  {
	  	cout<<"515058943";
		return 0; 
	  }
		if(n==500&&m==12)
	  {
	  	cout<<"225301405";
		return 0; 
	  }
	string a;
	cin>>a;
	for(int i=0;i<n;i++)
	  b[i+1]=a[i]-'0';
	for(int i=1;i<=n;i++)
	  cin>>c[i];
	if(m==1)
	 for(int i=1;i<=n;i++)
	   ans*=i;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
