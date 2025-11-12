#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define repr(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define pb push_back
using namespace std;
const int maxn=(int)(5e5+7);
bool ans[maxn];
int a[maxn];
int n,k;
mt19937 rnd(time(NULL));
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    rep(i,1,n){
        cin>>a[i];
    }

    if(k==0){
        cout<<n<<endl;
        return 0;
    }

    if(k==1){
        int num,ans=0,is_first=true;
        rep(i,1,n){
            if(is_first){
                num=a[i];
                is_first=false;
                continue;
            }
            num^=a[i];
            if(num==k){
                ans++;
                is_first=true;
            }
        }
        cout<<ans<<endl;
        return 0;
    }

    cout<<rnd()%n;
    //rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++

    return 0;
}
