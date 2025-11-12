#include <bits/stdc++.h>
using namespace std;
long long jc(int k){
    long long fin=1;
    for(int i=1;i<=k;i++){
        fin*=i;
        fin=fin%998244353;
    }
    return fin;
}

long long C(int a,int b){
    long long f=1;
    for(int i=b+1;i<=a;i++)
        f*=i;
    long long j=jc(a-b);
    return f/j;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int d[n]={};
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d,d+n);
    if(m!=n)
    cout<<(C(n,m)*jc(m))%998244353;
    else{
        cout<<jc(m)%998244353;
    }
    return 0;
}
