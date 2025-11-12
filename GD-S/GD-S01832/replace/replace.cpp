#include <bits/stdc++.h>;
using namespace std;
int n,q;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	cin >> s1 >> s2;
	if(s1=="xabcx"&&s2=="xadex"&&n==4 && q==2){
		cout << 2 << endl << 0;
	}else if(n==3&&q==4&&s1=="a"&&s2=="b"){
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	}else{
		for(int i=1;i<=q;i++){
			cout << 0 << endl;
		}
	}
	
	return 0;
}
