#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],ma=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int f=s[i]-'0';
			a[f]++;
			ma=max(ma,f);
		}
		
	}
	if(ma==0){
		cout<<0;
		return 0;
	}
	for(int i=ma;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
