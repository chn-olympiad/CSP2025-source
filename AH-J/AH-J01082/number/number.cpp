#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2 ;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2 ;i -= s3)
#define INF 0x7f7f7f7f
#define ll long long
using namespace std;
string s;
int n,a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.size();
	int i,f = 0;
	rep(i,1,n,1) if('0' <= s[i - 1] && s[i - 1] <= '9') a[s[i - 1] - '0']++;
	//~ rep(i,0,9,1) cout<<a[i]<<'\n';
	r(i,9,1,1){
		if(a[i]) f = 1;
		while(a[i]--) printf("%c",i + '0');
	}
	if(f) while(a[0]--) printf("%c",i + '0');
	else printf("%c",i + '0');
	return 0;
}
