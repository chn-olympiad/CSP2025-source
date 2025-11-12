#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int len,num[N],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if('0'<=s[i]&&s[i]<='9')num[++cnt]=s[i]-'0';
	}
	sort(num+1,num+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)printf("%d",num[i]);
}
