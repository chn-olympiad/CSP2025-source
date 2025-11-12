#include <bits/stdc++.h>
using namespace std;
const int N=505;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') cnt++;
	}
	if(cnt==s.size()){
		long long mul=1;
		int t=n;
		for(int i=1;i<=n;i++){
			mul*=t;
			t--;
		}
		cout<<mul;
	}
	return 0;
}
