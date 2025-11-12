#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005],cnt=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';	
		}
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}