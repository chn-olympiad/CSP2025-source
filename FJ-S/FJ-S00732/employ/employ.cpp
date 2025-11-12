#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0, f=1;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
//set<int> s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(), m=read();
	string s;
	cin >> s;
	for(int i=1;i<=n;i++){
		int x=read();
//		s.insert(x);
	}
	cout << m << endl;
	return 0;
}

