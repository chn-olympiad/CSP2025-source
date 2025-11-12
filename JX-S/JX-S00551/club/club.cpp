#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t,ans,a[N][5];
struct node{
    int ma,id;
}bu1[N],bu2[N],bu3[N];
bool cmp(node a,node b){
    return a.ma>b.ma;

}
struct node2{
    int a,b;
    int ma,id,idx;
}maz[N];
bool cmp2(node2 a,node2 b){
    return a.a+a.b<b.a+b.b;
}
int f[N],s[5],st[5];
int p=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(s,0,sizeof s);
        memset(st,0,sizeof st);
        ans=0;
        for(int i=1;i<=n;i++){
            int idd=0,d=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(j==2&&p==0){
                    a[i][j]!=0;
                    p=1;
                }
                if(j==3&&(p==0||p==1)){
                    if(a[i][j]!=0)p=2;
                }
                if(j==1)bu1[i].ma=a[i][j],maz[i].a=a[i][j];
                if(j==2)bu2[i].ma=a[i][j],maz[i].b=a[i][j];
                if(j==3)bu3[i].ma=a[i][j];
                if(a[i][j]>d)d=a[i][j],idd=j;
            }
            maz[i].ma=d,maz[i].id=idd,maz[i].idx=i;
        }
        int maxu=n/3;
        int mma=n/2;
        if(p==0){
            sort(bu1+1,bu1+n+1,cmp);
            for(int i=1;i<=mma;i++){
                ans+=bu1[i].ma;
            }
            cout<<ans<<"\n";
        }
        if(p==1){
            sort(maz+1,maz+n+1,cmp2);
            for(int i=1;i<=n;i++){
                if(!st[maz[i].id]){
                    s[maz[i].id]+=1;
                    if(s[maz[i].id>mma]){
                        st[maz[i].id]=1;
                    }
                }
                else{
                    if(st[maz[i].id]){
                        if(st[1]==0)ans+=a[maz[i].idx][1],s[maz[i].id];
                        else ans+=a[maz[i].idx][2],s[maz[i].id];
                    }
                    else{
                        ans+=maz[i].ma;
                        s[maz[i].id]++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
        if(maxu==0){
            int q=0,ans=0;
            for(int i=1;i<=3;i++){
                    ans=a[1][i];
                for(int j=1;j<=3;j++){
                    if(j==i)continue;
                    ans+=a[2][j];
                    q=max(ans,q);
                }
            }
            cout<<q<<endl;
            continue;
        }
    }
}

