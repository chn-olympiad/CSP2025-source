#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q,k=0;
    char a[1000],b[1000],r[1000],p[1000];
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        int n1=strlen(a);
        int n2=strlen(b);
    }
    for(int j=1;j<=q;j++){
        cin>>r>>p;
        int t1=strlen(r);
        int t2=strlen(p);
        if(n1==t1) k++;
        if(n2==t2) k++;
    }
    cout<<k;
}
