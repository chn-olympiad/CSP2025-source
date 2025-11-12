#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	int m=0;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++m]=s[i]-'0';
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--) cout<<a[i];	
	return 0;
}
