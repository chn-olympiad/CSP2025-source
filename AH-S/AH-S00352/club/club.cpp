#include<bits/stdc++.h>
using namespace std;
int T;
struct club{
    int a,b,c;
};
int cmp(club a,club b){
    return a.a>b.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.in","r",stdout);
    cin>>T;
    int q[5]={0};
    for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        club a[100005];
        for(int j=0;j<n;j++){
            int u,v,w;
            cin>>u>>v>>w;
            a[i].a=u;
            a[i].b=v;
            a[i].c=w;
        }
        if(a[0].b==a[0].c&&a[0].b==0){
            int z=n/2;
            sort(a,a+n,cmp);
            int cnt=0;
            for(int j=0;j<z;j++){
                cnt+=a[j].a;
            }
            q[i-1]=cnt;
        }
    }
    for(int i=0;i<T;i++){
        cout<<q[i]<<" ";
    }
    return 0;
}
