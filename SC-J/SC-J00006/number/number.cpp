#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[20];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=1;k<=a[i];k++){
			cout<<i;
		}
	}
	return 0;
} 