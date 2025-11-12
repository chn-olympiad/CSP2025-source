#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t;
struct mem{
    int d,fa;
}f[N];
int n,mx,num[4];
bool cmp(mem x,mem y){return x.d<y.d;}
void solve(){
    mx=0;
    memset(num,0,sizeof num);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int m=max({a,b,c});
        if(m==a){
            f[i].fa=1;
            if(b>c)f[i].d=a-b;
            else f[i].d=a-c;
            num[1]++;
        }else if(m==b){
            f[i].fa=2;
            if(a>c)f[i].d=b-a;
            else f[i].d=b-c;
            num[2]++;
        }else{
            f[i].fa=3;
            if(a>b)f[i].d=c-a;
            else f[i].d=c-b;
            num[3]++;
        }mx+=m;
        //cout<<d[i]<<' '<<m<<'\n';
    }int tag;
    if(num[1]>n/2)tag=1;
    else if(num[2]>n/2)tag=2;
    else if(num[3]>n/2)tag=3;
    else{
        cout<<mx<<'\n';
        return;
    }//cout<<mx<<' '<<tag<<' '<<num[tag]<<'\n';
    sort(f+1,f+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i].fa==tag){
            mx-=f[i].d;
            cnt++;
            num[tag]--;
        }if(num[tag]==n/2)break;
    }printf("%d\n",mx);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)solve();
    return 0;
}
