#include <bits/stdc++.h>
using namespace std;

const int N=1e6+50;
int ans[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int idx=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			ans[idx]=s[i]-'0';
			idx++;
		}
	}
	sort(ans,ans+idx);
	for(int i=idx-1;i>=0;--i){
		cout<<ans[i];
	}
	return 0;
} 