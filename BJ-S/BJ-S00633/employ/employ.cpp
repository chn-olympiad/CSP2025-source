#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 510;
int n,c[maxn],m;
char s[maxn];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    bool is_all_one=true;
    bool is_all_zero=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]=='0'){
            is_all_one=false;
        }else{
            is_all_zero=false;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(is_all_zero==true){
        cout<<0<<endl;
    }
    return 0;
}
