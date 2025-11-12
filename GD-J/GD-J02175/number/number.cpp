#include<bits/stdc++.h>
#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define D(i,a,b) for(register int i=a;i>=b;i=~-i)
#define ad(k) (k=-~k)
using namespace std;
string s;long long t[9];
int main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	F(i,0,n-1)if(s[i]>='0'&&s[i]<='9')t[s[i]-'0']++;
	D(i,9,0)F(j,1,t[i])cout<<i;
	return 0;
} 
