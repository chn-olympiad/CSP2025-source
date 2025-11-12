#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
string s;
int a[N],tot=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 