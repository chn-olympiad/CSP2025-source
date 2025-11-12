#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a;
int b;
cin>>b>>a;
int k;
cin>>k;
int s[1000]={};
s[0]=k;
for(int i=1;i<(a*b);i++)
{
	cin>>s[i];
}
sort(s,s+a*b);
int z=0;
for(int i=a*b-1;i>=a*b/2;i--)
{
	swap(s[i],s[a*b-i-1]);
}
for(int i=0;i<a*b;i++)
{
	if(s[i]==k)
	{
		z=i;
	}
}
z++;
int n;
if(z%b==0)
{
	n=z/b;
}
else
{
	n=z/b+1;
}
cout << n<<" ";
if(n%2==1)
{
	if(z%b==0)
	{
		cout << b;
		return 0;
	}
	cout << ceil(z%b);
}
if(n%2==0)
{
	if(z%b==0)
	{
		cout << 1;
		return 0;
	}
	cout << 1+b-ceil(z%b);
}
return 0;
}
