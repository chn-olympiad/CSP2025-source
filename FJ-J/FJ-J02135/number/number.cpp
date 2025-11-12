#include <bits/stdc++.h>
using namespace std;
string s,st[10000];
int a[10005],sum;
int main()
{
	cin>>s;
	for (int i=1;i<=10000;i++){
		if (s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[i]=s[i];
		}
	}
	sort(a+1,a+10000+1);
	for(int i=1;i<=10000;i++){
		st[i]=a[i];
		cout<<st[i];
	}
	return 0;
}
