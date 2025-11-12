#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int l=1,t;
char c,a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>c){
        if(isdigit(c)){
            a[++t]=c;
        }
    }
    sort(a+1,a+1+t,greater<int>());
    while(a[l]=='0'){
        l++;
    }
    for(int i=l;i<=t;i++){
        cout<<a[i];
    }
    if(l>t){
        cout<<0;
    }
    return 0;
}
//By Luogu Online Judge user 1400123
