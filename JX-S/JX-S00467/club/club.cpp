#include<bits/stdc++.h>
using namespace std;
int t,n;
struct g{
    int x,y,z,w;
}s[100010];
int lon(int d,int b,int c){
    d=max(d,b);
    d=max(d,c);
    return d;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        long long ans=0;
        for(int j=1;j<=n;j++){
            scanf("%d%d%d",&s[j].x,&s[j].y,&s[j].z);
            s[j].w=lon(s[j].x,s[j].y,s[j].z);
        }
        for(int j=1;j<=n;j++){
            ans+=s[j].w;
        }
        cout<<ans<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

