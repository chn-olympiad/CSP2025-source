#include<bits/stdc++.h>
using namespace std;
int n,a,l[5005],jc[10005];
long long jcc(int a){
    if(jc[a]) return jc[a];
    else if(a==1){
        jc[a]=1;
        return jc[a];
    }
    else {
        jc[a]=(a*jcc(a-1))%998244353;
        return jc[a];
    }
}
long long C(int nn,int mm){
    return jcc(nn)/jcc(nn-mm)/jcc(mm);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        l[a]++;
    }
    for(int i=3;j<=n;i++){
        
    }
    return 0;
}
//no time!!!!!!
//only 10 minutes left