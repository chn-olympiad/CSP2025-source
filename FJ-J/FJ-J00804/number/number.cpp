#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0, f=1;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
const int N=1e6+5;
int a[N], k=0;
bool cmp(int x, int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') a[++k]=s[i]-'0';
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		cout << a[i];
	}
	return 0;
}

