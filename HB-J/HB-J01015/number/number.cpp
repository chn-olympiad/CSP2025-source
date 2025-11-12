#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+86;
bool cmp(ll a,ll b){
    return a>b;
}
string s;
ll a[MAXN],x=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    ll s1=s.size();
    s=" "+s;
    for(ll i=1;i<=s1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            x++;
            a[x]=ll(s[i])-48;
        }
    }
    sort(a+1,a+x+1,cmp);
    for(ll i=1;i<=x;i++){
        cout<<a[i];
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
