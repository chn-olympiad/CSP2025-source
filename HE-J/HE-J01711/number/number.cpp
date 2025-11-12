#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,an;
int n;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			an+=s[i];
		}
	}
	sort(an.begin(),an.end());
	reverse(an.begin(),an.end());
	cout<<an;
	return 0;
}
