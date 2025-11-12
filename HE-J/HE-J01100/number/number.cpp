#include<bits/stdc++.h>
using namespace std;
int ans=0;
char a[1000001]; 
int j;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=s.length();
     for(int i=0;i<x;i++)
	 {
	 	if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
	 	{
	 		a[j]=s[i];
	 		j++;
		}
	 }
	 sort(a,a+j);
	 for(int i=j-1;i>=0;i--)
	 {
	 	cout<<a[i];
	 }
	 return 0; 
}
