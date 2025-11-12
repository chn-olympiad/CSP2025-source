#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    //cout<<s;
    vector <long long> vec;
    for (int i =0;i < s.length();i++){
        char t = s[i];
        if (t >= '0' && t <= '9'){
            long long num = t - '0';
            vec.push_back(num);
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    for (int i =0;i < vec.size() ;i++){
        printf("%lld",vec[i]);
    }

    return 0;
}