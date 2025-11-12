#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
long long u[200005],cnt;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(long long i=1;i<=q;i++){
        long long h=0;
        string x,y;
        cin>>x>>y;
        if(x==y){
            h=0;
        }
        else{
            for(long long i=1;i<=n;i++){
                if(x.find(a[i])!=-1){
                    string z;
                    z=x;
                    for(long long j=0;j<a[i].size();j++){
                        z[x.find(a[i])+j]=b[i][j];
                    }
                    if(z==y)h++;
                }

            }
            u[++cnt]=h;
        }
    }
    for(long long i=1;i<=cnt;i++){
        cout<<u[i]<<endl;
    }
    return 0;
}
