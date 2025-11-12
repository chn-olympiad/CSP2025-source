#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],cn[501],cs[501];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		cn[c[i]]++;
	}
	for (int i=0;i<s.length();i++)
		cs[i+1]=cs[i]+abs(s[i]-'1');
	sort(c+1,c+n+1);
	if (cs[n]==0){
		int s=1;
		for (int i=1;i<=n;i++)
		    s*=i%998244353;
	}
	return 0;
}
