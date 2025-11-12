#include<iostream>
#include<algorithm>
using namespace std ;
const int MAXN=1e6+2;
typedef long long ll ;
string s ;
bool flag=false;
ll n=0,ans[MAXN];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s ;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            n++;
            ans[n]=s[i]-'0';
            // if(s[i]!='0') flag=true ;
        }
    }
    /*
    if(flag==false){
        cout << 0 ;
        return 0 ;
    }
    */
    sort(ans+1,ans+n+1);
    for(int i=n;i>=1;i--) cout << ans[i] ;
    return 0 ;
}
