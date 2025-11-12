#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int MAXN=1e6+10;
int a[MAXN];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	int len=s.size(),j=0;
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	solve();
	return 0;
}
