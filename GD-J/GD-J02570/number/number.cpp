#include <bits/stdc++.h>
#define ll unsigned long long
#define endl "\n"
using namespace std;
const int MAXN=1e+6;
ll n=1,cnt=1,b[MAXN];
char a[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>a[n]) n++;
	n--;
	for(int i=1;i<=n;i++){
		if(a[i]-'0'>=0 && a[i]-'0'<=9) b[cnt]=a[i]-'0',cnt++;
	} 
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>1;i--) cout<<b[i];
	return 0;
} 
