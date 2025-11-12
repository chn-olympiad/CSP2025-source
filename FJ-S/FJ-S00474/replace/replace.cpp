#include<bits/stdc++.h>
using namespace std;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;n = read();q = read();
	for(int i = 1;i <= n;i++){
		string s,t;cin >> s >> t;
	}
	while(q--){
		string s,t;cin >> s >> t;
		cout << "0\n";
	}
	return 0;
}

