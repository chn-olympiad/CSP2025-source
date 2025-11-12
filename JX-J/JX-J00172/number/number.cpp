#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int l,idx,a[N];
bool cmp(int A,int B){
	return A > B;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	l = s.length();
	for(int i = 0 ; i < l ; i ++){
		if(s[i] >= '0' && s[i] <= '9')
			a[++ idx] = s[i];
	}
	sort(a + 1,a + idx + 1,cmp);
	for(int i = 1 ; i <= idx ; i ++)
		cout << (char)(a[i]);
	return 0;
}
