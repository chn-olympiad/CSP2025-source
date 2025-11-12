#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t,n;
struct node{
    int a,b,c;
}a[N];
int ans;
void dfs(int id,int fen,int x,int y,int z){
    if(id==n+1||x>n/2||y>n/2||z>n/2){
        ans=max(ans,fen);
        return;
    }
    if(x+1<=n/2)
    dfs(id+1,fen+a[id].a,x+1,y,z);
    if(y+1<=n/2)
    dfs(id+1,fen+a[id].b,x,y+1,z);
    if(z+1<=n/2)
    dfs(id+1,fen+a[id].c,x,y,z+1);
}
bool cmp(node a,node b){return a.a>b.a;}
int main(){
    cin>>t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    while(t--){
        cin>>n;
        if(n<=30){
            ans=0;
            for(int i=1;i<=10000;i++)a[i].a=a[i].b=a[i].c=0;
            for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                cin>>a[i].a>>a[i].b>>a[i].c;
                if(a[i].b==0)cnt++;
                if(a[i].c==0)cnt++;
            }
            sort(a+1,a+n+1,cmp);
            if(cnt==n*2){

                int sum=0;
                for(int i=1;i<=n/2;i++)sum+=a[i].a;
                cout<<sum<<endl;
                continue;
            }
            int dpa=0,dpb=0;
            for(int i=1;i<=n;i++){
                if(i<=n/2)
                dpa+=a[i].a;
                else dpb+=a[i].b;
            }
            for(int i=1;i<=n;i++){
                if(i<=n/2){
                    if(dpa-a[i].a+a[i].b+dpb>dpa+dpb)dpa-=a[i].a,dpb+=a[i].b;
                }
            }
            cout<<dpa+dpb<<endl;
        }
    }
    return 0;
}
