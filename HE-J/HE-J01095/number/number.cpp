#include <bits/stdc++.h>
using namespace std;
string s;
char c[100005];
int p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[p] = s[i];
			p++;
		}
	}
	sort(c,c+p);
	for(int i = p-1;i >= 0;i--) cout <<c[i];
}
