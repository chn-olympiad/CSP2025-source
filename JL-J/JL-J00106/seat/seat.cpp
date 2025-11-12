#include <bits/stdc++.h>
using namespace std;
int x[105],x2[13][13]={0};
int n,m,g,f=1,h=1,l,o;
int main(){
    cin>>n>>m;
    l=n;
    for(int i=1;i<=n*m;i++)
        cin>>x[i];
    g=x[1];
    o=1;
    sort(x+n*m,x+n*m+1);
    for(int i=1;i<=m;i++){
        for(int j=h;j<=l;j=j+f){
            x2[i][j]=x[o];
            o++;
        }
        if(f=1)
            f=-1;
        else
            f=1;
        if(h=1)
            h=n;
        else
            h=1;
        if(l=n)
            l=1;
        else
            l=n;
    }
    for(int i=1;i<=m;i++){
        for(int j=h;j<=l;j=j+f)
            cout<<x2[i][j];
        if(f=1)
            f=-1;
        else
            f=1;
        if(h=1)
            h=n;
        else
            h=1;
        if(l=n)
            l=1;
        else
            l=n;
    }
}


