#include <bits/stdc++.h>
using namespace std;
#define ll long long

//const ll N=10e6+6;
bool cmp(ll a,ll  b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ll a[1000001],sum=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            sum++;
        }
    }
    sort(a,a+s.size(),cmp);
    for(int j=0;j<sum;j++){
        cout<<a[j];
    }

    return 0;
}
