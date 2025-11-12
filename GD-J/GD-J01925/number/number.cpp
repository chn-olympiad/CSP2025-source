#include<bits/stdc++.h>
using namespace std;
const int maxn=1e1+5;
string s;
long long a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]--)cout<<i;
	cout<<'\n';
	return 0;
}
