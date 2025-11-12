#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int cnt=1;
string s;
char a[MAXN];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length();
	for(int i=0;i<len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt++] = s[i];
		}
	}
	sort(a+1,a+cnt);
	for(int i = cnt-1;i>=1;i--) cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
