#include<bits/stdc++.h>
using namespace std;
string s;
long long int a[10000005],x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1')	a[++x]=1;
		if(s[i]=='2')	a[++x]=2;
		if(s[i]=='3')	a[++x]=3;
		if(s[i]=='4')	a[++x]=4;
		if(s[i]=='5')	a[++x]=5;
		if(s[i]=='6')	a[++x]=6;
		if(s[i]=='7')	a[++x]=7;
		if(s[i]=='8')	a[++x]=8;
		if(s[i]=='9')	a[++x]=9;
		if(s[i]=='0')	a[++x]=0;
	}sort(a+1,a+x+1);
	for(int i=x;i>0;i--)	cout<<a[i];
	return 0;
} 