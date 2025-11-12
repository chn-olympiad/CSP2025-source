#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=1331,modd=0x3f3f3f3f;
map<string,string>re;
int l,r;
int n,q;
ll ans=0;
string a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    while(n--){
        cin>>a>>b;
        re[a]=b;
    }
    while(q--){
        cin>>a>>b;
        for(l=0;l<a.size();l++){
            if(a[l]!=b[l])
                break;
        }
        for(r=a.size()-1;r>=0;r--){
            if(a[r]!=b[r])
                break;
        }
        for(int i=0;i<=l;i++){
            for(int j=a.size()-1;j>=r;j--){
                string s1,s2;
                for(int k=i;k<=j;k++){
                    s1+=a[k];
                    s2+=b[k];
                }
                if(re[s1]==s2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}

