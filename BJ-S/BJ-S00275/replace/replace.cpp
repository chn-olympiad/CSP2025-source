#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
long long n,q,ans;//ull hsh[5000005];
map<string,string>qwq;
set<string>fd;
string sq,sw,nw,tgt,t,x,y,z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int ii=1;ii<=n;ii++){
        cin>>sq>>sw;
        qwq[sq]=sw;
        fd.insert(sq);
    }

    for(int ii=1;ii<=q;ii++){ans=0;
        cin>>nw>>tgt;t.clear();
        for(int l=0;l<nw.size();l++){
            y.clear();
            for(int r=l;r<nw.size();r++){
                y+=nw[r];z.clear();
                for(int k=r+1;k<nw.size();k++){
                    z+=nw[k];
                }
                if(qwq[y]!=""){t=x+qwq[y]+z;
                if(t==tgt){ans++;
                //cout<<x<<" "<<qwq[y]<<" "<<z<<" "<<l<<" "<<r<<endl;
                }}
            }
            x+=nw[l];
        }
        cout<<ans<<endl;
    }
    return 0;
}
