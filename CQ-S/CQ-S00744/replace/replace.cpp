#include <bits/stdc++.h>
using namespace std;
unordered_map <string,string> t;
int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		string a,b;
		cin>>a>>b;
		t[a]=b;
	} while(q--) {
		string a,b;
		cin>>a>>b;
		a=' '+a; b=' '+b;
		int len=(int)b.size()-1,res=0;
		if((int)a.size()!=len) {
			cout<<0<<endl;
			continue ;
		}
		vector <bool> pd1(len+5,0);
		vector <bool> pdn(len+5,0);
		for(int i=len;i>=1;i--) {
			pdn[i]=pdn[i+1];
			if(a[i]!=b[i]) {
				pdn[i]=1;
			}
		}
		for(int i=1;i<=len;i++) {
			pd1[i]=pd1[i-1];
			if(a[i]!=b[i]) {
				pd1[i]=1;
			}
		}
		for(int i=1;i<=len;i++) {
			for(int j=i;j<=len;j++) {
				string p=a.substr(i,j-i+1);
				string d=b.substr(i,j-i+1);
				if(t[p]==d && !pd1[i-1] &&!pdn[j+1]) {
					res++;
//					cout<<p<<"->"<<d<<endl;
				}
			}
		} cout<<res<<endl;
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
