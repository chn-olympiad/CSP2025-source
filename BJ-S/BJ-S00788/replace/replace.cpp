#include <bits/stdc++.h>
using namespace std;
long long n,q,ans=0;
string h[5000010],h2[5000010],x,x2,y,y2,z,z2;
map<string,string> m;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (long long i=1;i<=n;i++){
        string u,v;
        cin >> u >> v;
        m[u]=v;
    }
    while(q--){
        string a,b,x="",x2="",y="",y2="",z="",z2="";
        ans=0;
        cin >> a >> b;
        for (long long i=0;i<a.size();i++){
            h[i]=h[i-1]+a[i];
        }
        for (long long i=0;i<b.size();i++){
            h2[i]=h2[i-1]+b[i];
        }
        if (a.size()!=b.size()){
            cout << 0;
        }
        else{
            for (long long i=0;i<=a.size();i++){
                for (long long j=i;j<=a.size();j++){
                    if (i==0){
                        y=h[j-1];
                        y2=h2[j-1];
                        for (long long k=j;k<a.size();k++){
                            z=z+a[i];
                        }
                        for (long long k=j;k<b.size();k++){
                            z2=z2+b[i];
                        }
                        if (m[y]==y2 && z==z2){
                            ans++;
                        }
                    }
                    else{
                        x=h[i-1];
                        x2=h2[i-1];
                        for (long long k=i;k<=j-1;k++){
                            y=y+a[i];
                        }
                        for (long long k=i;k<=j-1;k++){
                            y2=y2+b[i];
                        }
                        for (long long k=j;k<a.size();k++){
                            z=z+a[i];
                        }
                        for (long long k=j;k<b.size();k++){
                            z2=z2+b[i];
                        }
                        if (x==x2 && m[y]==y2 && z==z2){
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}
