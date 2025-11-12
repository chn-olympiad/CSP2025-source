#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s; ll len; priority_queue<ll> q;
int main(){
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	cin>>s; len=s.length();
	for(ll i=0,x;i<len;i++) if(s[i]>='0'&&s[i]<='9'){x=s[i]-'0'; q.push(x);}
	while(!q.empty()){cout<<q.top(); q.pop();}
	return 0;
} 
