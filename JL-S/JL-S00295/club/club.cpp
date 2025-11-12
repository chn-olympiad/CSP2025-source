#include<bits/stdc++.h>
using namespace std;
struct x{
    int y,z,t,i,j=-1,k=-1;
};
bool cmp(x a,x b){
    return a.i<b.i;
}
int dfs(x a[],int b,int c,int d,int e,int f,int g){
    if(f==b){
        return g;
    }
    int h=0;
    if(c<b/2){
        h=max(h,dfs(a,b,c+1,d,e,f+1,g+a[f].y));
    }
    if(d<b/2){
        h=max(h,dfs(a,b,c,d+1,e,f+1,g+a[f].z));
    }
    if(e<b/2){
        h=max(h,dfs(a,b,c,d,e+1,f+1,g+a[f].t));
    }
    return h;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a;
    cin>>a;
    while(a--){
        int b;
        cin>>b;
        x c[b];
        int d,e=0;
        for(d=0;d<b;d++){
            cin>>c[d].y;
            cin>>c[d].z;
            cin>>c[d].t;
            if(c[d].t!=0){
                e=1;
            }
        }
        if(e==0){
            for(d=0;d<b;d++){
                c[d].i=c[d].z-c[d].y;
            }
            sort(c,c+b,cmp);
            int f=0;
            for(d=0;d<b/2;d++){
                f+=c[d].y;
            }
            for(d=b/2;d<b;d++){
                f+=c[d].z;
            }
            cout<<f<<endl;
            continue;
        }
        cout<<dfs(c,b,0,0,0,0,0)<<endl;
    }
    return 0;
}
