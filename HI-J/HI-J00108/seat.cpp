#include<bits/stdc++.h> 
using namespace std;
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int cnt=0;
	int h=0,s=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			cnt++; 
		}
	}
	cnt=cnt+1;
	 if(cnt%n==0)
	 {
	 	s=cnt/n;
	 
	 if(cnt%n==0)
	 {
	 	h=n;
	 }
	 else
	 {
	 	h=cnt%n;
	 }
	 }
	 else
	 {
	 	s=cnt/n+1; 
	 
	 if(cnt%n==0)
	 {
	 	h=n;
	 }
	 else
	 {
	 	h=cnt%n;
	 }
	 }
	if(s%2==1)
	{
		cout<<s<<" "<<h;
	}
	else
	{
		h=n-h+1; 
	cout<<s<<" "<<h;
	}
	
	
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
