#include<bits/stdc++.h>
using namespace std;
int cnt[100];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<=len-1;i++){
        if(s[i]>='0'&&s[i]<='9') cnt[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(cnt[i]>0){
            cout<<i;
            cnt[i]--;
        }
    }
    return 0;
}

