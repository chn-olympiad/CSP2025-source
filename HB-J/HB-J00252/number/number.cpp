#include <bits/stdc++.h>
using namespace std;
string str;
int num[15],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>str;
	for(int i=0;i<int(str.size());i++){
		if(str[i]>='0'&&str[i]<='9'){
			num[str[i]-'0']++;
			ans++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
