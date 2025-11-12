#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<math.h>
#include<cstring>
using namespace std;
int a[10];
long long R=0;
string s;
int main(){
	feropen("number.in","r",stdin);
	feropen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=strlen(s);i++)
	{
		if(int(s[i])<=57&&int(s[i])>=48)
		{
			a[s[i]]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]){
			R*=10;
			R+=a[i];
			a[i]--;
		}
	}
	cout<<R;
	return 0;
}
