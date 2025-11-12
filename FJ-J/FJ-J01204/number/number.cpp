#include<bits/stdc++.h>
using namespace std;
int n=10 ;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[n];
	int c[n],b;
	b=n+1;
	for(int i=1;i<=n;i++)
	{cin>>a[i];
	
     if(a[i]=='1')
    c[i]=1;
     if(a[i]=='2')
    c[i]=2;
     if(a[i]=='3')
    c[i]=3;
     if(a[i]=='4')
    c[i]=4;
     if(a[i]=='5')
    c[i]=5;
     if(a[i]=='6')
    c[i]=6;
     if(a[i]=='7')
    c[i]=7;
     if(a[i]=='8')
    c[i]=8;
     if(a[i]=='9')
    c[i]=9;
     if(a[i]=='0')
    c[i]=0;
    sort(c+1,c+b);
	}for(int k=n;k>=1;k--)
	{
	cout<<c[k];}
	
	return 0;
} 
