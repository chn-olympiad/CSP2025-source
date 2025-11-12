#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int num[1000005],k;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>s;
    for(ll i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[k]=int(s[i]-'0');
            k++;
        }
    }
    sort(num,num+k);
    if(num[k-1]==0){
        cout<<0;
        return 0;
    }
    for(ll i=k-1;i>=0;i--){
       cout<<num[i];
    }
    return 0;
}
