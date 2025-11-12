#include<bits/stdc++.h>
using namespace std;
int cnt;
char a,ans[1000010];
bool cmp(char x,char y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a) {
		if(a>='0'&&a<='9')ans[cnt++]=a;
	}
	sort(ans,ans+cnt,cmp);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
