#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,a[N],tp;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9') a[++tp]=s[i]-'0';
	}
	sort(a+1,a+1+tp);
	for(int i=tp;i>=1;i--) cout<<a[i];
	return 0;
}
