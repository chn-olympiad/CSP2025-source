#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m;
char str[N],ans[N];
bool cmp(char x,char y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++){
		if(str[i]>='0'&&str[i]<='9') ans[++m]=str[i];
	}
	sort(ans+1,ans+m+1,cmp);
	for(int i=1;i<=m;i++) cout<<ans[i];
	return 0;
}
