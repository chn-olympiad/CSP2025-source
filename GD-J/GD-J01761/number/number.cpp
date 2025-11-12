#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
string s;
int a[maxn];
int tot;
bool cmp(const int &a,const int &b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	for(int i = 0;i < s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(int i = 1;i <= tot;i++){
		printf("%lld",a[i]);
	}
	return 0;
} 
