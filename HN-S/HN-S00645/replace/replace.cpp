#include<bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
const int N=2e5+5;
int n,q;
string a[N],b[N];
ll ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    f(i,1,n)
        cin>>a[i]>>b[i];
    f(i,1,q){
        string x,y;
        cin>>x>>y;
        int l=0,r=1;
        while(l<=(int)x.length()-1){
            f(j,1,n){
                if(x.substr(l,r)==a[j]){
                    if((l>0?x.substr(0,l-1):"")+b[j]+x.substr(r+1,x.length()-1)==y){
                        ans++;
                    }
                }
            }
            l++;
            if(l>r){
                r++;
                l=0;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
