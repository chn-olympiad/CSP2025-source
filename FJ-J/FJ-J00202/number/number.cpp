#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000005
string s;
int e[N],ans;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0'){
			e[++ans]=s[i]-'0';
		}
	}
	sort(e+1,e+ans+1);
	for(int i=ans;i>=1;--i)cout<<e[i];
	return 0;
}
