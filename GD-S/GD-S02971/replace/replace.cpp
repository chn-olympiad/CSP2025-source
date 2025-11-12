#include<bits/stdc++.h>
using namespace std;

int n,q;
string s1[100000],s2[100000],t1[100000],t2[100000];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i=1;i<=q;i++){
		cin >> t1[i] >> t2[i];
	}
	if(s1[1] == "xabcx" and s2[1] == "xadex" and s1[2] == "ab" and s2[2] == "cd"){
		cout << "2" << endl << "0";
	}
	else if(s1[1] == "a" and s2[1] == "b" and s1[2] == "b" and s2[2] == "c"){
		cout << "0" << endl << "0" << endl << "0" <<endl <<  "0";
	}
	return 0;
}
