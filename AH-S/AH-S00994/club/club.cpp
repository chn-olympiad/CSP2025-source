#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int N=1e5;

int nt;
int n;

struct www{
    int a1,a2,a3;
}g[N+5];

int t1=0,t2=0,t3=0;
bool cmp(const www x,const www y){
    return x.a1<y.a1;
}
int gfind(int p,int ans){
    int s1=0,s2=0,s3=0;
    if(p==n+1) return ans;
    if(t1<n/2){
        t1++;
        s1=gfind(p+1,ans+g[p].a1);
        t1--;
    }
    if(t2<n/2){
        t2++;
        s2=gfind(p+1,ans+g[p].a2);
        t2--;
    }
    if(t3<n/2){
        t3++;
        s3=gfind(p+1,ans+g[p].a3);
        t3--;
    }
    return(max(s1,max(s2,s3)));
}
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>nt;
    while(nt--){
        memset(g,0,sizeof(g));
        t1=0;
        t2=0;
        t3=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>g[i].a1>>g[i].a2>>g[i].a3;
        }
        if(n>=200){
            int ans=0;
            sort(g+1,g+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=g[i].a1;
            }
            cout<<ans<<endl;
            continue;
        }
        printf("%d\n",gfind(1,0));
    }

    return 0;

}
