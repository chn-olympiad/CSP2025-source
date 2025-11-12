#include<bits/stdc++.h>
using namespace std;
struct a1{
int a,b,c;
}n[1567898];
int t,m,f[1234556];
bool cmp(a1 a,a1 b){
return a.a>b.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
cin>>t;
while(t--){
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n[i].a>>n[i].b>>n[i].c;
    }
    if(m==2){
        cout<<max({n[0].a+n[1].b,n[0].a+n[1].c,n[0].b+n[1].a,n[0].b+n[1].c,n[0].c+n[1].a,n[0].c+n[1].b})<<endl;
    }else{
        sort(n,n+m,cmp);
        cout<<n[1].a+n[0].a<<endl;
    }
}
return 0;
}
