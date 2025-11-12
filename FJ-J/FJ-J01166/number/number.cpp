#include <bits/stdc++.h>
#define int long long
#define y0 __Y0
#define y1 __y1
#define pb push_back
#define pii pair<int,int>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=1e6+5;
string s;
int a[N],top;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	FILE("number");
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;s=' '+s;
	int n=s.length(); 
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++top]=s[i]-'0';
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		cout<<a[i];
	}
	return 0;
}
