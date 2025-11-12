#include <bits/stdc++.h>
using namespace std;
int jec(int a){
    if(a==0){
        return 1;
    }
    return a*jec(a-1);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string tes;
    cin>>tes;
    int cna[n+1];
    for(int i=1;i<=n;i++){
        cin>>cna[i];
    }
    sort(cna,cna+n);
    int hd=0;
    int p=1;
    int c=0;
    for(int i=1;i<=n;i++){
        if(cna[i]<=hd){
            hd++;
        }
        if(i!=1&&cna[i]==cna[i-1]){
            c++;
        }else{
            p*=jec(c);
        }
    }
    cout<<p;
    return 0;
}