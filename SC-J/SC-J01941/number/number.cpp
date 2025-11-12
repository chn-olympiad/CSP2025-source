#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e2;
string s,str;
int siz,num[N],idx,cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	siz = s.size();
	for(int i = 0;i < siz;i++){
		if( s[i] >= '0' && s[i] <= '9' ) num[++idx] = s[i] - '0';
	}
	sort( &num[1],&num[idx] + 1 );
	reverse( &num[1],&num[idx] + 1 );
	for(int i = 1;i <= idx;i++) cout << num[i];
	return 0;
}