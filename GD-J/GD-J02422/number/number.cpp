#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
string ab;
const long long N=1e6+5;
char a[N];
int b[N];
bool mysort(int a,int b)
{
return 	a>=b;
}

int sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ab;
   
	for(int i=0;i<ab.length();i++)
	{
		a[i]=ab[i];
       if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			b[i]=a[i]-'0';
		}
		if(a[i]=='0')
		{
			sum++;
			b[i]=0;
		}
	}
	sort(b,b+ab.length(),mysort);
	for(int i=0;i<ab.length();i++)
	{
		if(b[i]!=0) cout<<b[i];
		else break;
	}
		for(int i=0;i<sum;i++)
	{
		cout<<"0";
	}
	
	return 0;
}
