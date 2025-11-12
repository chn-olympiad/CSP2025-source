#include <bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;

string s;
string ans;
char a[N],idx;

bool cmp(char x,char y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length();
	for (int i=1;i<=len;++i){
		if (s[i-1] >= '0' && s[i-1] <= '9')
			a[++idx] = s[i-1];
	}
	sort(a+1,a+1+idx,cmp);
	for (int i=1;i<=idx;++i) cout << a[i];
	
	
	
	
	return 0;
} 
