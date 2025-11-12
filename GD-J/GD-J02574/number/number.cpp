#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6;
ll m[100];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(isdigit(str[i])){
			m[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=m[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
