#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	memset(a,0,sizeof a);
	while(cin>>s) {
		if(s>='0'&&s<='9') a[s-'0']++;
	}
	for(int i=9;i>=0;i--) {
		while(a[i]--) cout<<i;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
