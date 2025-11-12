#include<bits/stdc++.h>
using namespace std;
string s;
int t[30];
string ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) t[s[i]-'0']++;
    }
    for(int i='9';i>='0';i--){
        for(int j=1;j<=t[i-'0'];j++) ans+=i;
    }
    while(ans.size()>1&&ans[0]=='0') ans.erase(0,1);
    cout<<ans;
	return 0;
}

