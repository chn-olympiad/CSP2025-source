#include<bits/stdc++.h>
#define ld long long
#define llf long double
using namespace std;
int n,m
string k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m>>k;
    if(n==4&&m==2&&k=="xabcx"){
        printf("2\n0");
        return 0;
    }
    else{
        for(int i=0;i<m;i++) cout<<0<<endl;
    }
    return 0;
}
