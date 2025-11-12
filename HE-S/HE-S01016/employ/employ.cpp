#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[505];
string s;
int c[505];
int sum;
int co;
int f(int n)
{
	if(n-1==0) 
	{
	return 1;
	}
	return f(n-1)+(n-1)*n;
 } 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	if(s[i]==1)
	 	{
	 		sum++;
		 }
	 }
	 if(sum==n)
	 {
	 	if(m==2)
	 	{
	 		co=f(n);
		 }else
		 {
		 	co=f(n);
		 }
	 }
	 if(m==n)
	 {
	 	if(sum!=n)
	 	{
	 		co=0;
		 }
	 }
	// if(m==1)
	// {
	// 	
	// }
	 cout<<co%998%244%353;
	return 0;
 } 
