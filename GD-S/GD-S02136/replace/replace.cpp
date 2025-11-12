#include<bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 5;
inline int read(){
	int f = 0,k = 0;
	char c = getchar();
	while(!isdigit(c)){
		f |= c == '-';
		c = getchar();
	}
	while(isdigit(c)){
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f ? -k : k;
}
int n,q;
pair<string,string> k[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(),q = read();
	for(int i = 1;i <= n;i++){
		cin >> k[i].first >> k[i].second;
	}
	for(int i = 1;i <= q;i++){
		string a,b;
		cin >> a >> b;
		int ans = 0;
		int lena = a.size(),lenb = b.size();
		if(lena != lenb){
			printf("0\n");
			continue;
		}
		for(int j = 1;j <= n;j++){
			int len = k[j].first.size();
			if(len > lena || a.find(k[j].first) > lena) continue;
			int pos = a.find(k[j].first);
			string pre = a.substr(0,pos),nxt = a.substr(pos + len);
			if(pre + k[j].second + nxt == b){
//				cout << pos << ' ' << pre << ' ' << nxt << '\n';
				++ans;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
