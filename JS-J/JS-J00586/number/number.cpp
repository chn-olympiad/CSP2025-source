#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s;//cin
    for(auto i:s){//cover string
        if(isdigit(i)){//isdigit
            t[i-'0']++;//tong++
        }
    }
    for(int i=9;i>=0;i--){
        while(t[i]--){
            cout<<i;
        }
    }
    cout<<'\n';
    return 0;
}
