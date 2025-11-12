#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+6;
int a[MAXN],len;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			len++;
			a[len]=s[i]-'0';
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
