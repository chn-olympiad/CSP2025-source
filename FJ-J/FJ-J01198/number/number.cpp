#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
char a[N];
int p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int k = s.size();
	for(int i = 0; i < k; i++) {
		if(s[i] >= '0'&&s[i] <= '9') {
			a[p] = s[i];
			p++;
		}
	}
	sort(a,a + p);
	for(int i = p - 1; i >= 0; i--)
	   cout << a[i];
	return 0;
} 
