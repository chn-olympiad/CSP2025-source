#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[100001],s1[100001];
string a[100001],a1[100001];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i =1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>a1[i];
		if(a[i]==s[i] && s1[i]==a1[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


