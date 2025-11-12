#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
char s2[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i2=1;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			s2[i2]=s[i];
			i2++;
		}
	}
	for(int i=1;i<=i2;i++){
		for(int j=i;j>=1;j--){
			if(s2[j]<s2[j+1]){
				char t=s2[j+1];
				s2[j+1]=s2[j];
				s2[j]=t;
			}
		}
	}
	for(int i=1;i<=i2;i++){
		cout<<s2[i];
	}
	return 0;
}