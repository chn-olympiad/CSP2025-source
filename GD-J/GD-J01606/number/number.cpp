#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1145141],bx=1;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[bx]=s[i]-'0';
			bx++;
		}
	}
	sort(a+1,a+1+bx);
	for(int i=bx;i>=2;i--) cout<<a[i];
}
