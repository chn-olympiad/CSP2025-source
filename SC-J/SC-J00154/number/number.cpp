#include <bits/stdc++.h>
using namespace std;
string a;
int s[1000001],z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)if(a[i]>='0'&&a[i]<='9')s[++z]=a[i]-'0';
	sort(s+1,s+1+z);
	for(int i=z;i>=1;i--)cout<<s[i];
	return 0;
}