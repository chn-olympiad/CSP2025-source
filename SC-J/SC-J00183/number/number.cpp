#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
string s;
int A[14];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	REP(z,0,len-1)if(s[z]>='0' && s[z]<='9')A[s[z]-'0']++;
	for(int z=9;z>=0;z--)REP(i,1,A[z])cout<<z;
	return 0;
}