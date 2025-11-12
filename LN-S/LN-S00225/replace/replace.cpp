#include<bits/stdc++.h>
using namespace std;
int n,q,d,kl[500005],jl2;
struct node{
    int a[500005];
    int dx;
};
map<int,node>c;
string a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    c.clear();
    for(int i=1;i<=n;i++){
            int jl,jl2;
        cin>>a>>b;
        for(int j=0;j<a.size();j++)
            if(a[j]=='b')jl=j;
        for(int j=0;j<b.size();j++)
            if(b[j]=='b')jl2=j;
        c[jl2-jl].a[++c[jl2-jl].dx]=a.size();
    }
    for(int i=1;i<=q;i++){
        int jl,jl2,ans=0;
        cin>>a>>b;
        d=a.size();
        for(int j=0;j<a.size();j++)
            if(a[j]=='b')jl=j;
        for(int j=0;j<b.size();j++)
            if(b[j]=='b')jl2=j;
        for(int i=1;i<=c[jl2-jl].dx;i++)
            if(c[jl2-jl].a[i]<=d)ans++;
        kl[i]=ans;
    }
    for(int i=1;i<=q;i++)
        cout<<kl[i]<<endl;
}
