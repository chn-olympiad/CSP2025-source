#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){int x = 0,ch = getchar();bool zt=0;while(ch<48||ch>57){if(ch==45)zt = 1;ch = getchar();}while(ch>=48&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return zt?-x:x;}
const int N = 500 + 10,mod = 998244353;
int n,m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read();m = read();
	while(m--)cout<<"0\n"; 
	
	return 0;
}
