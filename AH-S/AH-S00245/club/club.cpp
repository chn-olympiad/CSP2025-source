#include<iostream>
#include<algorithm>
using namespace std;
const int N = 3e5+11;
struct c{
    int id,v,want,l,s,fjs;
}happy[N];
bool cmp(c x,c y){
//    if(x.l==y.l){
        if(x.s==y.s)return x.v>y.v;
        return x.s<y.s;
//    }
//    else return x.l>y.l;
}
int cnt[4],n;
bool vis[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int cn = 0;
        int calc=0;
        for(int i = 1;i<=n;i++)vis[i]=0;
        for(int i = 1;i<=3;i++)cnt[i]=0;
        for(int i = 1;i<=n;i++){
            int a,b,c,ttt=1,cnt1=3,cnt2=3,cnt3=2;
            cin>>a>>b>>c;
            if(a==0)ttt++;
            if(b==0)ttt++;
            if(c==0)ttt++;
            if(b>c)cnt1=2;
            if(a>c)cnt2=1;
            if(a>b)cnt1=1;
            if(a!=0)happy[++cn]={i,a,1,ttt,max(b,c),cnt1};
            if(b!=0)happy[++cn]={i,b,2,ttt,max(a,c),cnt2};
            if(c!=0)happy[++cn]={i,c,3,ttt,max(a,b),cnt3};
        }
        sort(happy+1,happy+cn+1,cmp);
//        cout<<"hapy"<<endl;
//        for(int i = 1;i<=cn;i++){
//            cout<<happy[i].id<<' '<<happy[i].v<<' '<<happy[i].want<<' '<<happy[i].l<<endl;
//        }
//        cout<<"edn"<<endl;
        for(int i = 1;i<=cn;i++){
            int id = happy[i].id;
            int v = happy[i].v;
            int want = happy[i].want;
            if(!vis[id]&&cnt[want]<(n/2))calc+=v,vis[id]=1,cnt[want]++;
        }
        cout<<calc<<endl;
    }
    return 0;
}
