#include<bits/stdc++.h>
#define int long long

using namespace std;
string str;
int nums[10];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9'){
			nums[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<nums[i];j++){
			cout<<i;
		}
	}
	return 0;
}
