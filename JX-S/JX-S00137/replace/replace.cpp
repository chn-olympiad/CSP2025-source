#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
struct t{
    string q,p;
}t[200005];
string a,b;

void dfs(string x){
    for(long long i=1;i<=n;i++){
        long long pos=x.find(t[i].q);
        //cout<<pos<<endl;
        while(pos!=-1){
            string y="";
            for(long long j=0;j<pos;j++){
                y+=x[j];
            }
            y+=t[i].p;
            for(long long j=pos+t[i].p.length();j<x.length();j++) y+=x[j];
            if(y==b){
                s++;
            }
            pos=x.find(t[i].q,pos+1);
        }
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        cin>>t[i].q>>t[i].p;
    }
    for(long long i=1;i<=m;i++){
        cin>>a>>b;
        s=0;
        dfs(a);
        printf("%lld\n",s);
    }
    return 0;
}
