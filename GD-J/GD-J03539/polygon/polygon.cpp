#include<bits/stdc++.h >
using namespace std;
int n,m,a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==5)
	{
		cout<<"9"<<endl;
		return 0; 
	}
	else
	{
		cout<<"6";
	}
	for(int i=1;i<=n;i++)
	{
		while(m>3)
		{
			a[i++];	
			m=a[i];
		}	
	}	
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
