#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    bool l = true;
    int h = s.size()-1;
    for(int i=1;i<=h;i++){
		if(s[i] != '1'){
			l = false;
		}
	}
	long long ans = 1;
	if(l == true){
		for(int i=1;i<=n;i++){
			ans *= i;
			ans %= 998244353;
		}
		ans %= 998244353;
		cout<<ans;
		return 0;
	}
	cout<<0;
    return 0;
}
