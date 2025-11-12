#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=201;
int n,T,ans;
struct node{
    int a,b,c;
}t[N];
bool cmp1(node a,node b){
    return a.a>a.b;
}
bool cmp2(node a,node b){
    int x=max({abs(a.a-a.b),abs(a.a-a.c),abs(a.b-a.c)}),y=max({abs(b.a-b.b),abs(b.b-b.c),abs(b.a-b.c)});
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)
            cin>>t[i].a>>t[i].b>>t[i].c;
        if(n==100000){
            sort(t+1,t+1+n,cmp1);
            int sum=0;
            for(int i=1;i<=n/2;i++)
                sum+=t[i].a;
            cout<<sum<<endl;
        }else{
            sort(t+1,t+1+n,cmp2);
            int sza=0,szb=0,szc=0;
            for(int i=1;i<=n;i++){
                if(t[i].a>t[i].b&&t[i].a>t[i].c){
                    if(sza==n/2)
                        if(t[i].b>t[i].c)
                            szb++,ans+=t[i].b;
                        else
                            szc++,ans+=t[i].c;
                    else
                        sza++,ans+=t[i].a;
                }else if(t[i].b>t[i].a&&t[i].b>t[i].c){
                    if(szb==n/2)
                        if(t[i].a>t[i].c)
                            sza++,ans+=t[i].a;
                        else
                            szc++,ans+=t[i].c;
                    else
                        szb++,ans+=t[i].b;
                }else{
                    if(szc==n/2)
                        if(t[i].a>t[i].b)
                            sza++,ans+=t[i].a;
                        else
                            szb++,ans+=t[i].b;
                    else
                        szc++,ans+=t[i].c;
                }
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}