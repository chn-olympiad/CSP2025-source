#include<bits/stdc++.h>
using namespace std;
char a[100001];int b[100001];
long long sum;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
int l=strlen(a);
for(int i=0;i<=l-1;i++)
{
	
	if(a[i]=='0')
	sum=sum*10;
	else if(a[i]=='1')
	sum=sum*10+1;
	else if(a[i]=='2')
	sum=sum*10+2;
    else if(a[i]=='3')
	sum=sum*10+3;
    else if(a[i]=='4')
	sum=sum*10+4;
    else if(a[i]=='5')
	sum=sum*10+5;
	else if(a[i]=='6')
	sum=sum*10+6;
	else if(a[i]=='7')
	sum=sum*10+7;
	else if(a[i]=='8')
	sum=sum*10+8;
	else if(a[i]=='9')
	sum=sum*10+9;
}
int ss1=sum,l1;
while(ss1!=0)
{
	++l1;
	ss1=ss1/10;
}
for(int i=0;i<=l1;i++)
{
	int ss=sum%10;
	sum=sum/10;
	b[i]=ss;
}
for(int j=0;j<=l1;j++)
{
	for(int i=0;i<=l1;i++)
{
	if(b[i]<=b[i+1])
	{
	int q=b[i+1];
	b[i+1]=b[i];
	b[i]=q;
    }

}
	
}
for(int i=0;i<=l1;i++)
	cout<<b[i];
return 0;
}
