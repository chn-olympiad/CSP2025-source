#include<bits/stdc++.h>
// #define ll long long
// #define inf INT_MAX
using namespace std;
const int N=1e6+7;
const int M=1e6+7;
const int mod=1e9+7;
int a[N];int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin >>s;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
    }
    sort(a+1,a+1+cnt,greater<int>());
    for(int i=1;i<=cnt;i++)cout<<a[i];
    cout<<endl;
    return 0;
}