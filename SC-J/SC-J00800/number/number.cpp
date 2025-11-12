#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
char a[N];
long long b[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(a+1);
	for(int i=1;i<=strlen(a+1);i++)if(a[i]<='9'&&a[i]>='0')b[++cnt]=a[i]-'0';
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<b[i];
	return 0;
}