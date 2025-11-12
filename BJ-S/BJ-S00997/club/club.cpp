#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
struct node{
    ll a,b,c;
    ll ms1,ms2,id;
}cl[100005];
bool cmp1(node x,node y){
    return x.a>y.a;
}
bool cmp2(node x,node y){
    return x.ms1>y.ms1;
}
bool cmp3(node x,node y){
    return x.ms2>y.ms2;
}
int n;
void ch(){
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<cl[i].ms2<<" "<<cl[i].id<<endl;
    }
}
int vis[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&cl[i].a,&cl[i].b,&cl[i].c);
            cl[i].id=i;
        }
        ll res=0;
        sort(cl+1,cl+n+1,cmp1);
        for(int i=1;i<=n;i++){
            res+=cl[i].a;
            cl[i].ms1=cl[i].b-cl[i].a;
        }
        //cout<<res<<endl;
        sort(cl+1,cl+n+1,cmp2);
        for(int i=1;i<=n/2;i++){
            res+=cl[i].ms1;
            vis[cl[i].id]=1;
        }
        //cout<<res<<endl;
        for(int i=1;i<=n;i++){
            if(vis[cl[i].id]==1){
                cl[i].ms2=cl[i].c-cl[i].b;
            }else{
                cl[i].ms2=cl[i].c-cl[i].a;
            }
        }
        sort(cl+1,cl+n+1,cmp3);
        //ch();
        //cout<<res<<endl;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cl[i].ms2>0){
                cnt++;
                res+=cl[i].ms2;
            }
            if(cnt==n/2){
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
