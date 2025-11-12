#include<iostream>
#include<bits/stdc++.h>
using  namespace std;
long long int a[1000001],n=0,i,t;
string s;
int main{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(i=0;i<=s.size();i++)
    {
		if(s[i]>='0'&&s[i]<='9')a[n]+=s[i]-'0',n++;
	}
	for(i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i-1]<a[i])t=a[i-1],a[i-1]=a[i],a[i]=t;
			}
	}
	for(i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
