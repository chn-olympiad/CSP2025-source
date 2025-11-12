#include <bits/stdc++.h>
using namespace std;
string a;
int b[200];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        b[a[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(b[i]){
            cout<<i;
            b[i]--;
        }
    }
    return 0;
}