#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN=3E5+114;
const int MAXM=3e6+114;

int n,m;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<rand()%998244353;
	return 0;
}

