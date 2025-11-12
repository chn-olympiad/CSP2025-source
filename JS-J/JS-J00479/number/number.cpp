#include<bits/stdc++.h>
using namespace std;
string s;
int bar[15],sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            bar[s[i]-'0']++;
        }
    }
    bool ze=0;
    for(int i=9;i>=0;i--){
        if(i!=0&&bar[i]>0) ze=1;
        for(int j=0;j<bar[i];j++){
            if(ze==0&&i==0){
                cout<<0;
                return 0;
            }
            else cout<<i;
        }
    }

    return 0;
}
