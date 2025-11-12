#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int cmp(ll x,ll y){
    return x>=y;
}
string s;
ll x[N],cnt,a,b,c,d,e,f,g,aa,bb;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    ll z=s.size();
    for(ll i=0;i<z;i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            x[cnt]=s[i]-'0';
        }
    }
    for(int i=1;i<=cnt;i++){
        if(x[i]==1) a++;
        if(x[i]==2) b++;
        if(x[i]==3) c++;
        if(x[i]==4) d++;
        if(x[i]==5) e++;
        if(x[i]==6) f++;
        if(x[i]==7) g++;
        if(x[i]==8) aa++;
        if(x[i]==9) cout<<9;
        if(x[i]==0) bb++;
    }
    for(int i=1;i<=aa;i++)
            cout<<8;
    for(int i=1;i<=g;i++)
            cout<<7;
    for(int i=1;i<=f;i++)
            cout<<6;
    for(int i=1;i<=e;i++)
            cout<<5;
    for(int i=1;i<=d;i++)
            cout<<4;
    for(int i=1;i<=c;i++)
            cout<<3;
    for(int i=1;i<=b;i++)
            cout<<2;
    for(int i=1;i<=a;i++)
            cout<<1;
    for(int i=1;i<=bb;i++)
            cout<<0;
    return 0;
}
