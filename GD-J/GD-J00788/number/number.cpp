#include<bits/stdc++.h>
using namespace std;
string s;
int a[100100],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s)if(c>='0'&&c<='9')a[t]=c-'0',++t;
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)cout<<a[i];
	return 0;
} 
