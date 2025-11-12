#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int v[10];
//fc D:\GD-J02485\number\number3.ans D:\GD-J02485\number\number3.out
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	int flag=0;
	for (int i=0;i<n;i++) {
		if (s[i]>='0'&&s[i]<='9') {
			v[s[i]-'0']++;
			if (s[i]!='0') {
				flag=1;
			}
		}
	}
	if (flag==0) {
		printf("0");
	}else {
		for (int i=9;i>=0;i--) {
			for (int j=1;j<=v[i];j++) {
				printf("%d",i);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
