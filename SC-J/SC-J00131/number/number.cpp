#include<bits/stdc++.h>
#define LL long long
#define rep(i,k,n) for(LL i=k;i<=n;i++)
using namespace std;
bool cmp(char a,char b){
	return a>b;}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s2="";cin>>s;
	for(char& c:s)
		if(c>='0'&&c<='9')
			s2+=c;
	sort(s2.begin(),s2.end(),cmp);
	cout<<s2;}