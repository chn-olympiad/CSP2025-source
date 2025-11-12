#include<bits/stdc++.h>
using namespace std;
struct a1{
string a,b;
}d[236534];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
int n,q,s=0;
string o,p;
cin>>n>>q;
for(int i=0;i<n;i++)cin>>d[i].a>>d[i].b;
for(int i=0;i<q;i++){
    cin>>o>>p;
    for(int j=0;j<n;j++){
        if(d[j].a.size()>o.size())continue;
        for(int k=0;k<=o.size()-d[j].a.size();k++){
            if(o.substr(k,d[j].a.size())==d[j].a&&p.substr(k,d[j].a.size())==d[j].b){
                    string z=o;
                for(int ii=k;ii<k+d[j].a.size();ii++)z[ii]=d[j].b[ii-k];
            if(z==p)s++;
            }
        }
    }
    cout<<s<<endl;
    s=0;
}
return 0;
}
