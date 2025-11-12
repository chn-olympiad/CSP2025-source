#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			tot++;
			a[tot] = s[i] - '0';
		}
	}
	sort(a + 1,a + tot + 1,greater<int>());
	for(int i = 1;i <= tot;i++)cout << a[i];
	return 0;
}	
