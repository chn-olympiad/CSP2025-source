#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[10];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			f[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=f[i];j++){
			cout<<i;
		}
	}
    return 0;
}
