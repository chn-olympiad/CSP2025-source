#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
char p[N];
int k,l;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9')p[++k]=s[i];
		if(s[i]=='0')++l;
	}
	sort(p+1,p+1+k);
	for(int i=k;i>=1;i--)cout<<p[i];
	for(int i=1;i<=l;i++)cout<<0;
	return 0;
}