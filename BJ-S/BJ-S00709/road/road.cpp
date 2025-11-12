#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
struct str{
    int x,y,z;
}a[1000010],b[20][10010],tmp[1100010];
int prec[20];
int tmpn;
int n,m,k;
bool cmp(const str &x,const str &y){
    return x.z<y.z;
}
int FA[10020];
void init(){
    for(int i=1;i<=n+k;i++){
        FA[i]=i;
    }
}
int getfa(int x){
    if(FA[x]==x){
        return x;
    }
    FA[x]=getfa(FA[x]);
    return FA[x];
}
void Merge(int x,int y){
    int fax=getfa(x),fay=getfa(y);
    if(fax!=fay){
        FA[fax]=fay;
    }
}
int lowbit(int x){
    return x&(-x);
}
int popcount(int x){
    int bac=0;
    while(x){
        bac++;
        x-=lowbit(x);
    }
    return bac;
}
//int CNT=0;
int kru(){
    sort(tmp+1,tmp+1+tmpn,cmp);
    init();
    int bac=0;
    for(int i=1;i<=tmpn;i++){
        if(getfa(tmp[i].x)!=getfa(tmp[i].y)){
            Merge(tmp[i].x,tmp[i].y);
            bac+=tmp[i].z;
        }
    }
    //CNT+=tmpn+log2(tmpn)*tmpn;
    return bac;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    bool flag=1;
    for(int i=1;i<=k;i++){
        cin >> prec[i];
        bool tmpflag=0;
        for(int j=1;j<=n;j++){
            b[i][j].x=j;
            b[i][j].y=i+n;
            cin >> b[i][j].z;
            if(b[i][j].z==0){
                tmpflag=1;
            }
        }
        flag&=(prec[i]==0);
        flag&=tmpflag;
    }
    if(flag||k==0){
        for(int i=1;i<=m;i++){
            tmpn++;
            tmp[tmpn]=a[i];
        }
        int tmpans=0;
        for(int i=1;i<=k;i++){
            tmpans+=prec[i];
            for(int j=1;j<=n;j++){
                tmpn++;
                tmp[tmpn]=b[i][j];
            }
        }
        cout << tmpans+kru();
        return 0;
    }
    int R=(1<<k)-1;
    int ans=1e18;
    for(int s=0;s<=R;s++){
        tmpn=0;
        for(int i=1;i<=m;i++){
            tmpn++;
            tmp[tmpn]=a[i];
        }
        int tmpans=0;
        for(int i=1;i<=k;i++){
            if((s>>(i-1))&1){
                tmpans+=prec[i];
                for(int j=1;j<=n;j++){
                    tmpn++;
                    tmp[tmpn]=b[i][j];
                }
            }
        }
        //CNT+=tmpn;
        ans=min(ans,tmpans+kru());
        //cerr << CNT << endl;
    }
    cout << ans;
    return 0;
}
