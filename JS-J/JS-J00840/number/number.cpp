#include<bits/stdc++.h>
#define N 12
using namespace std;
string s;
bool flg=0;
long long ans[N],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[s[i]-'0']++;
        }
    }
    for(int i=9;i>0;i--){
        for(int j=1;j<=ans[i];j++){
            cout<<i;
            flg=1;
        }
    }
    if(flg==1){
        for(int i=1;i<=ans[0];i++){
            cout<<0;
        }
    }else{
        cout<<0;
    }
    return 0;
}
