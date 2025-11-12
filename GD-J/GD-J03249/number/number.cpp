#include<bits/stdc++.h>
using namespace std;
int a[1000010],c;
string s;
int zd(int x,int y)
{
return x>=y;	
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
 	cin>>s;
 	for(int i=0;i<s.size();i++)
 	{
 	 if(s[i]>='0'&&s[i]<='9')
	 a[++c]=s[i]-48; 	
	}
	sort(a+1,a+1+c,zd);
	for(int i=1;i<=c;i++)
	cout<<a[i];
 return 0;	
} 
