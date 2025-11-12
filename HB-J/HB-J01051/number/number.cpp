#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fr(xx,aa,bb) for(xx=aa;xx<=bb;xx++)
#define rf(xx,aa,bb) for(xx=aa;xx>=bb;xx--)
const ll N=5e6;
const ll inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;

int t[13];
string s;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ll i,j,k,l,m;

    cin>>s;
    fr(i,0,s.size()-1){
        char ch=s[i];
        if(isdigit(ch))t[ch-'0']++;
    }
    rf(i,9,0)fr(j,1,t[i])cout<<i;


    // fprintf(stderr,"used time = %ldms\n\n",1000*clock()/CLOCKS_PER_SEC);
    return 0;
}
/*

*/
//g++ number.cpp -o test -O2 -std=c++14 -static