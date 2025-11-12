#include <bits/stdc++.h>
using namespace std;
//freopen //freopen //freopen //freopen //freopen //freopen //freopen
string s;int a[1000010],n;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s;int l=s.length();
	for(int i=0;i<l;i++)
		if(isdigit(s[i])) a[++n]=s[i]-'0';
	sort(a+1,a+n+1,[](int a,int b){return a>b;});
	for(int i=1;i<=n;i++) cout<<a[i];
	fclose(0);
}
