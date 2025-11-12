#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,b[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;cin>>a;
	for(auto i:a) if(i>='0'&&i<='9') b[++n]=i-'0';
	sort(b+1,b+n+1,greater<int>());
	if(b[1]==0) return printf("0"),0;
	for(int i=1;i<=n;++i) printf("%d",b[i]);
	return 0;
}
