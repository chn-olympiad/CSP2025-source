#include<bits/stdc++.h> 
#define int long long
#define x first
#define y second
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f,mod=1e9+7;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
/*
09:01 
Task1 done.
*/
string s;
int num[N],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i])) num[cnt++]=s[i]-'0';
	sort(num,num+cnt);
	while(cnt) cout<<num[--cnt];
	return 0;
}
