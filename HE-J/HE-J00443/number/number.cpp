#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = strlen(s),lens = 0;
	for (int i = 0;i < l;i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[lens] = s[i] - '0';
			lens++;
		}
	}
	sort(a,a + lens,cmp);
	for (int i = 0;i < lens;i++){
		cout << a[i];
	}
	return 0;
}
