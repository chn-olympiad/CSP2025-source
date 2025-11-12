#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    string s;
    cin>>s;
    char maxn='0'-1;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            mp[s[i]]++;
            maxn=max(int(maxn),int(s[i]));
        }
    }
    if(maxn=='0'){
        cout<<0;
        return 0;
    }
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        int t=it->second;
        for(int i=1;i<=t;i++){
            cout<<it->first;
        }
    }
	return 0;
}
