#include<bits/stdc++.h>
using namespace std;
int res[1000050];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int cnt=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            res[cnt]=(int)s[i]-'0';
            cnt++;
        }
    }
    sort(res,res+cnt,greater<int>());
    for(int i=0;i<cnt;i++){
        cout<<res[i];
    }
    return 0;
}
