#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int tot=1;
void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[tot++]=s[i]-'0';
		}
	}
	sort(a+1,a+tot);
	for(int i=tot-1;i>=1;i--) cout<<a[i];
	
}


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	return 0;
}

