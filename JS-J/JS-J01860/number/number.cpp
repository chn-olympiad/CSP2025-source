#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string s;
ll oc[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) oc[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=oc[i];j++){
            cout<<i;
        }
    }
	return 0;
}
