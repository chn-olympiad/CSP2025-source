#include <bits/stdc++.h>
#define LL long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=10e3+10;
bool cmp(int a,int b){
    return a>b;
}
string s,t;
int a[N];
int x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    IOS;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[x]=(s[i]-48);
            x++;
        }
    }
    sort(a,a+x+1,cmp);
    for(int i=0;i<x;i++){
        cout<<a[i];
    }





    return 0;
}
