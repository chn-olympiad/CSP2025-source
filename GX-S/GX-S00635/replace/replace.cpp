#include <bits/stdc++.h>
using namespace std;
struct s{
    string c;
    string d;
}f[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q,sum=0,be=0,en=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>f[i].c>>f[i].d;
    }
    while(q--){
        string a,b,x,z;
        cin>>a>>b;
        for(int i=1;i<=n;i++){
            if(f[i].c==a && f[i].d==b){
               sum++;
            }
        }
        for(int j=0;j<=a.length();j++){
                if(a[j]!=b[j]){
                    be=j;
                    break;
                }
        }
        for(int j=a.length();j>=0;j--){
                if(a[j]!=b[j]){
                    en=j;
                    break;
                }
        }
        for(int i=be;i<=en;i++){
            x+=a[i];
            z+=b[i];
        }
        cout<<x<<" "<<z<<endl;
        for(int i=1;i<=n;i++){
            if(f[i].c==x && f[i].d==z){
                sum++;
            }
        }
        cout<<sum<<endl;
        sum=0;be=0;en=0;
    }
    return 0;
}
