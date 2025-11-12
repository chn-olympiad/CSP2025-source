#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct c{
    int a,b,c;
}f[100005];
bool cmpa(c a,c b){
    return a.a>b.a;
}
bool cmpb(c a,c b){
    return a.b>b.b;
}
bool cmpc(c a,c b){
    return a.c>b.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>f[i].a>>f[i].b>>f[i].c;
        }
        sort(f+1,f+1+n,cmpa);
        sum+=f[1].a+f[2].a+f[3].a;
        f[1].a=f[2].a=f[3].a=0;
        f[1].b=f[2].b=f[3].b=0;
        f[1].c=f[2].c=f[3].c=0;
        sort(f+1,f+1+n,cmpb);
        sum+=f[1].b+f[2].b+f[3].b;
        f[1].a=f[2].a=f[3].a=0;
        f[1].b=f[2].b=f[3].b=0;
        f[1].c=f[2].c=f[3].c=0;
        sort(f+1,f+1+n,cmpc);
        sum+=f[1].c+f[2].c+f[3].c;
        f[1].a=f[2].a=f[3].a=0;
        f[1].b=f[2].b=f[3].b=0;
        f[1].c=f[2].c=f[3].c=0;
        cout<<sum<<endl;
    }
    return 0;
}
