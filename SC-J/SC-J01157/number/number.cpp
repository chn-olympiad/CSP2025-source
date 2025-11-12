#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int ans[N],cn;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			ans[++cn]=c-'0';
		}
	}
	sort(ans+1,ans+cn+1);
	for(int i=cn;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}