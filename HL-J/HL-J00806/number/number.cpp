#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
namespace hcx{
    int a[11];
	void main(){
		string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if('0'<=s[i]&&s[i]<='9'){
                a[s[i]-'0']++;
            }
        }
        for(int i=9;i>=0;i--){
            for(int j=1;j<=a[i];j++){
                cout<<i;
            }
        }
	}
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	hcx::main();
	return 0;
}