#include<bits/stdc++.h>
using namespace std;
#define INT long long
string in;
string sorted;
bool comp(char a,char b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>in;
    for(INT i=0;i<in.length();++i){
        if(in[i]>='0'&&in[i]<='9'){
            sorted+=in[i];
        }
    }
    sort(sorted.begin(),sorted.end(),comp);
    cout<<sorted;
    return 0;
}
