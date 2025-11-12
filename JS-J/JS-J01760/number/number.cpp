#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+5;
string str;
ll shu[N],ch=0,len=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>str;
    len=str.size();
    for(ll i=0;i<len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            ch++;
            shu[ch]=str[i]-'0';
        }
    }
    sort(shu+1,shu+1+ch);
    for(ll i=ch;i>=1;i--){
        cout<<shu[i];
    }
    return 0;
}
