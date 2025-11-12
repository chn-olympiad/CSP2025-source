#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+5;
char c[N];
int i,n,t,a[N],ans[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(cin>>(c+1),n=strlen(c+1),i=1;i<=n;a[i]=(c[i]>='0'&&c[i]<='9'?c[i]-'0':10),i++);
	for(sort(a+1,a+1+n),i=1;i<=n;i++) if(a[i]<10) ans[++t]=a[i];else break;
	for(;t;cout<<ans[t--]);
	return 0;
}
