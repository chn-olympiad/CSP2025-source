#include<bits/stdc++.h>;
using namespace std;
const int N=1e6+5;
string s;
int num,a[N],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        int dig=int(s[i]);
        if(dig>=48&&dig<=57){
                cnt++;
            a[cnt]=(s[i]-'0');
        }
    }
    sort(a+1,a+1+cnt);
    if(a[cnt]==0){
        cout<<0;
        return 0;
    }
    for(int i=cnt;i>=1;i--){
        cout<<a[i];
    }

    return 0;
}
