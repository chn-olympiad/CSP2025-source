#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,st,len,cnt[21];char a[N],ans[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1),n=strlen(a+1);
	for(int i=1;i<=n;i++)
	  if('0'<=a[i]&&a[i]<='9') cnt[a[i]-'0']++;
	for(int i=9;i>=0;i--)
	  for(;cnt[i];cnt[i]--) ans[++len]=(char)('0'+i);
	st=1;
	while(ans[st]=='0'&&st<len) st++;
	for(int i=st;i<=len;i++) printf("%c",ans[i]);
	return 0;
}
