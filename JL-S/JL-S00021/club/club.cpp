#include<bits/stdc++.h>
using namespace std;\
struct node{
    int x,y,z;
}b[100005];
bool f1(node f,node r){
    return f.z>r.z;
}
int a[100005][6],g[100005],h[100005],t,n,f[100005][5],l;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>b[(i-1)*3+j].z;
                a[i][j]=b[(i-1)*3+j].z;
                b[(i-1)*3+j].x=i,b[(i-1)*3+j].y=j;
            }
        }
        sort(b+1,b+3*n+1,f1);
        int sum=0,ans=0;
        int t=1;
        for(int i=1;i<=n*3;i++){
            if(!g[b[i].x]&&h[b[i].y]<n/2){
                ans+=b[i].z;
                h[b[i].y]++,g[b[i].x]=1;
                t++;
            }
            b[i].x=0,b[i].y=0,b[i].z=0;
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) g[i]=0,h[i]=0;
    }
    return 0;
}

