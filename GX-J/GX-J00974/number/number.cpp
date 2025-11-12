#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>s;
    int lens=s.size();
    for(int i=0;i<lens;i++){
        if(s[i]<='z' and s[i]>='a') continue;
        s1+=s[i];
    }
    sort(s1.begin(),s1.end());
    reverse(s1.begin(),s1.end());
    cout<<s1;
    return 0;
}
