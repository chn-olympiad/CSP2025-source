#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,q,c,d,u,v;
int s[1000];
int l[105];
bool o=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    q=s[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(s[a]<s[j]){
                a=j;
                o=1;
            }
        }
        if(o){
            o=0;
            b=s[a];
            s[a]=s[i];
            s[i]=b;
            a=0;
        }
    }
    for(int i=1;i<=n*m;i++){
        if(q==s[i]){
            q=i;
            break;
        }
    }
    if(q%n==0){
        c=q/n;
    }else{
        c=q/n;
        c++;
    }
    for(int i=1;i<=n;i++){
        l[i]=i;
    }
    for(int i=n+1;i<=n*2;i++){
        l[i]=n-u;
        u++;
    }
    v=n*2;
    d=l[q%v];
    cout<<c<<' '<<d;
    return 0;
}

