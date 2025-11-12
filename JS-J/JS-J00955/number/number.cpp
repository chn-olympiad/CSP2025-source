#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[10],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    s="#"+s;
    for(int i=1;i<=n;i++)
        for(char j='0';j<='9';j++)
            if(s[i]==j){
                cnt[j-'0']++;
                break;
            }
    for(char j='9';j>='0';j--)
        while(cnt[j-'0']--) cout<<j;
    return 0;
}
