#include<bits/stdc++.h>
using namespace std;
#define __ string
#define _ int
__ _o;
_ o_[1000086],_o_;
_ main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>_o;
    for(_ i=0;i<_o.size();i++){
        if(_o[i]>='0'&&_o[i]<='9'){
            o_[_o_]=_o[i]-'0';
            _o_++;
        }
    }
    sort(o_,o_+_o_);
    for(_ i=_o_-1;i>=0;i--)cout<<o_[i];
    return 0;
}
