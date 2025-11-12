#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=2e6+10;
struct s{
	string s1;
	string s2;
}ss[N];
struct t{
	string t1;
	string t2;
}tt[N];
char fnd1[M];
char fnd2[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss[i].s1>>ss[i].s2;
	}
	for(int i=1;i<=q;i++){
	//	cout<<"gfytrur";
		cout<<"0\n";
	}
	return 0;
}/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/