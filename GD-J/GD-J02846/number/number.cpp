#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))a[++k]=s[i]-'0';
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=k;j++){
		if(a[j]==i)cout<<a[j];
	}
	}
	return 0;
} 
