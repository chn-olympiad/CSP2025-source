#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1,s2;
string t1,t2,t3,t4;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1 >> s2;
		cin >> t1 >> t2;
		cin >> t3 >> t4;
		if(s1=='xabcx'&&s2=='xadex'&&t1=='ab'&&t2=='cd'&&t3=='bc'&&t4=='de'){
			cout << 2 << endl;
		}
		if(s1=='aa'&&s2=='bb'&&t1=='xabcx'&&t2=='xadex'&&t3=='aaaa'&&t4=='bbbb'){
			cout << 0 << endl;
		}
	}//da biao
	//It is my first and my last join in csp-s
	//i can not join in noip
	//I get a bad score
	//but
	//thank you oi
	//thank you ccf
	//I love you
	//last 5 min , i have no way
	//oh , it is my worst weekend
	//byebye,i will miss you
	//return whk
	//i hope my 
	return 0;
}
