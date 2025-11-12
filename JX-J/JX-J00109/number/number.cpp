#include<bits/stdc++.h>
using namespace std;
int cnt[10]={0};

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') cnt[1]++;
        else if(s[i]=='2') cnt[2]++;
        else if(s[i]=='3') cnt[3]++;
        else if(s[i]=='4') cnt[4]++;
        else if(s[i]=='5') cnt[5]++;
        else if(s[i]=='6') cnt[6]++;
        else if(s[i]=='7') cnt[7]++;
        else if(s[i]=='8') cnt[8]++;
        else if(s[i]=='9') cnt[9]++;
        else if(s[i]=='0') cnt[0]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
