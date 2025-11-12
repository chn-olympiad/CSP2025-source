#include<bits/stdc++.h>
using namespace std;
long long n,m,l,a[20000800];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++l]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--) cout<<a[i]; 
}
