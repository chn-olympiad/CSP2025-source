#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define str string
#define bstr basic_string
int main(){
    #ifndef DXX_DEBUG
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
    #endif
    str a;
    cin>>a;
    vec<char>nums;
    for(auto i:a){
        if(i>='0'&&i<='9')nums.push_back(i);
    }
    sort(nums.rbegin(),nums.rend());
    for(auto i:nums)cout<<i;
    cout<<"\n";
    return 0;
}
