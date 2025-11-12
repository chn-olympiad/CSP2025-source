#include<bits/stdc++.h>
#define N 1001000
using namespace std;
char str[N]; int a[10],n,m;
int main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>(str+1),n=strlen(str+1);
	for(int i=1;i<=n;i++) if('0'<=str[i]&&str[i]<='9') a[str[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=a[i];j++) cout<<i;
	return 0;
}