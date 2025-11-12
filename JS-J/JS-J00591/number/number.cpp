#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
long long cnt[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<cnt[i];j++){
            cout<<i;
        }
    }
    return 0;
}
