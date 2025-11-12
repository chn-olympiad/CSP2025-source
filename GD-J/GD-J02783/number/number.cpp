#include<bits/stdc++.h>
using namespace std;
int n,l;
char s[1000001],b[1000001];
signed main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)if(s[i]>='0'&&s[i]<='9')b[++l]=s[i];
	sort(b+1,b+1+l);
	for(int i=l;i>0;i--)cout<<b[i];
	return 0;
}
