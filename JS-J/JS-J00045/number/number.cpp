#include<bits/stdc++.h>
#define N 1000010
using namespace std;
string s;
int l,x;
int cnt[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            x=s[i]-'0';
            cnt[x]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
