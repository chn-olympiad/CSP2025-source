#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=27;
int a[N]={0};
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(0<=s[i]-'0' && s[i]-'0'<=9){
			a[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
