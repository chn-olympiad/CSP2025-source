#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL n=s.size();
	for(LL i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') t+=s[i];
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t;
	return 0;
}
