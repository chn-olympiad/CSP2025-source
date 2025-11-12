#include<bits/stdc++.h>
using namespace std;
#define var long long
#define ln '\n'

string x,y;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>x;
    for(var i=0;i<x.size();i++){
        char it=x[i];
        if(it>='0' && it<='9'){
            y=y+it;
        }
    }

    sort(y.begin(),y.end(),greater<char>());

    cout<<y<<ln;
    return 0;
}
