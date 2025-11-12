#include<bits/stdc++.h>
using namespace std;
int n,q,ls[200005],lt,sum,bs[200005],bc[200005],tb,gb;
string s[200005],c[200005],t,g;
inline int findb(string x){
	int len=x.size();
	for(int i=0;i<len;i++){
		if(x[i]=='b') return i;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i] >> c[i];
		ls[i]=s[i].size();
		bs[i]=findb(s[i]);
		bc[i]=findb(c[i]);
	}
	for(int i=1;i<=q;i++){
		cin >> t >> g;
		lt=t.size(),sum=0;
		tb=findb(t),gb=findb(g);
		for(int j=1;j<=n;j++){
			if(s[i].size()==c[i].size() && gb-tb==bc[j]-bs[j] && tb+ls[j]-bs[j]-1<=lt && tb-bs[j]>=0){
				sum++;
			}
		}
		cout<<sum<<"\n";
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

*/
