#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long j=1,s,x=1;
	char a[1000001],f[1000001];
	cin.getline(a,' ');
	for (int i=1;i<=1000001;i++)
	{
		if (a[i]<'0'||a[i]>'9')  a[i]=' ';
	}
	for (int i=1;i<=1000001;i++)
	{
		if (a[i]!=' '){
			f[x]=a[i];
			x++;
		} 
	}
	s=x;
    for (int k=1;k<=x;k++)
	{
		for (int i=1;i<s;i++)
	    {
		if (f[i+1]>f[i])  swap(f[i+1],f[i]);
	    }
	    s=s-1;
	}
	for (int i=1;i<=x;i++)
	  cout<<f[i];
	return 0;
}