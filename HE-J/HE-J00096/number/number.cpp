#include<iostream>
using namespace std;
int n,a[10];
string ans; 
int main() 
{
	for(int i=0;i<=9;i++)
	{
		a[i]=0;
	}
	cin>>ans;
	 for(int i=0;i<=ans.size();i++)
	 {
	 	if(ans[i]=='1')
	 	{
	 		a[1]++;
		 }
		if(ans[i]=='0')
	 	{
	 		a[0]++;
		 }
		if(ans[i]=='2')
	 	{
	 		a[2]++;
		 }
		if(ans[i]=='3')
	 	{
	 		a[3]++;
		 }
		if(ans[i]=='4')
	 	{
	 		a[4]++;
		 }
		if(ans[i]=='5')
	 	{
	 		a[5]++;
		 }
	if(ans[i]=='6')
	 	{
	 		a[6]++;
		 }
		if(ans[i]=='7')
	 	{
	 		a[7]++;
		 }
			if(ans[i]=='8')
	 	{
	 		a[8]++;
		 }
		if(ans[i]=='9')
	 	{
	 		a[9]++;
		 }
		
	 }
	 for(int i=9;i>=0;i--)
	 {
	 	for(int j=1;j<=a[i];j++)
	 	{
	 		cout<<i;
		}
	  } 
	return 0;
}
