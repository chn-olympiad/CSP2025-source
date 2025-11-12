#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	char c[N];
	long long cnt=0;
	for(size_t i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') c[++cnt]=s[i];
	}
	sort(c+1,c+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<c[i];
	return 0;
}
