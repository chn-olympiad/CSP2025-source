#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int num[N];
char s[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1),tot=0;
	for(int i=1; i<=n; i++){
		if(isdigit(s[i])) num[++tot]=s[i]-'0';
	}
	sort(num+1,num+tot+1,greater<int>());
	for(int i=1; i<=tot; i++) cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}