#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
char s[MAXN];
int a[MAXN],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=strlen(s);
	for(int i=0;i<=len-1;i++){
		if('0'<=s[i] and s[i]<='9') a[cnt++]=s[i]-'0';
	}
	sort(a,a+cnt,greater<int>());
	for(int i=0;i<=cnt-1;i++){
		cout << a[i];
	}
	return 0;
}
