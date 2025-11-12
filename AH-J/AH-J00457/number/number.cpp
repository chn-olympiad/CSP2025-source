#include"bits/stdc++.h"
using namespace std;
const int N=20;
int flag[N];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int g=s.size();
	for(int i=0;i<g;i++){
		int yu=s[i]-'0';
		if(yu>=0&&yu<=9){
			flag[yu]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=flag[i];j++){
			cout<<i;
		}
	}
	return 0;
}
