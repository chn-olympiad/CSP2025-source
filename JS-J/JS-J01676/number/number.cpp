#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto ch:s){
        if(ch>='0'&&ch<='9')a[ch-'0']++;
    }
    for(int fsx=9;fsx>=0;fsx--){
        while(a[fsx]>0){
            cout<<fsx;
            a[fsx]--;
        }
    }
    return 0;
}
