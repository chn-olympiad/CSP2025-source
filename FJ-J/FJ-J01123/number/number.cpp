#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
string str;
int vis[N];
int main(){
//	freopen("number4.in","r",stdin);
//	freopen("number4.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if('0'<=str[i]&&str[i]<='9'){
			vis[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=vis[i];j++){
			cout<<i;
		} 
	}
	return 0;
}
