#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            a[s[i]-'0']++;
        }
    }
    bool fl=0;
    for(int i=9;i>=0;i--){
        if(a[i]){
            fl=1;
        }
        if(i==0 && !fl)
        {
            cout<<0;
        }
        else{
            while(a[i]){
                cout<<i;
                a[i]--;
            }
        }
    }
    return 0;
}