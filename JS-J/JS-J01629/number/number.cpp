#include "bits/stdc++.h"
using namespace std;
string s;
long long b[200];

int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
       if((s[i]>='0')&&(s[i]<='9')){
            //cout<<s[i]-'0';
            b[s[i]-'0']++;
        }

    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b[i];j++)
            cout<<i;
    }
    return 0;
}
