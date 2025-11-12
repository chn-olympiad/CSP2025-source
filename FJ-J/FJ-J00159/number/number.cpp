#include<bits/stdc++.h>
using namespace std;
string s,a[100];
int l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']+=s[i];
	for(int i=10;i>=0;i--) cout<<a[i];
	return 0;
}
