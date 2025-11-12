#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++m]=s[i]-'0';
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--)
		cout<<a[i];
	return 0;
}
