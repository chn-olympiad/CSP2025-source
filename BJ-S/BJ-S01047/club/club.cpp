#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll a[100010][10],b[100010],ans,cnt[10],cnttrue[10];
struct Node{
    int score,num;
    bool f=1;
}c[10][100010];
bool cmp(Node x,Node y){
    return x.score<y.score;
}
void judge(int d,int x){
    if(d==1){
        ll cha=cnttrue[1]-n/2;
        if(cha<=0) return ;
        sort(c[1]+1,c[1]+cnt[1],cmp);
        for(int j=1;j<=cnt[1];j++){
            ll i=c[1][j].num;
            if(c[1][j].f==false) continue;
            ll ma=max(a[i][2],a[i][3]);
            if(ma-a[i][1]>=0||a[x][1]+ma-a[i][1]>=0){
                cha--;
                cnttrue[1]--;
                c[1][j].f=false;
                if(ma==a[i][2]){
                    b[i]=2;
                    c[2][++cnt[2]].num=i;
                    c[2][cnt[2]].score=a[i][2];
                    cnttrue[2]++;
                    judge(2,i);
                }else {
                    b[i]=3;
                    c[3][++cnt[3]].num=i;
                    c[3][cnt[3]].score=a[i][3];
                    cnttrue[2]++;
                    judge(3,i);
                }
            }else continue;
            if(cha==0) return ;
        }
        ll mi=0x3f3f3f3f,minum,minum2;
        for(int j=1;j<=cnt[1];j++){
            ll i=c[1][j].num;
            if(c[1][j].f==false) continue;
            if(a[x][1]-a[i][1]+max(a[i][2],a[i][3])<mi){
                mi=a[x][1]-a[i][1]+max(a[i][2],a[i][3]);
                minum=i;
                minum2=j;
            }
        }
        c[1][minum2].f=false;
        if(a[minum][2]>=a[minum][3]){
            b[minum]=2;
            c[2][++cnt[2]].num=minum;
            c[2][cnt[2]].score=a[minum][2];
            cnttrue[2]++;
            judge(2,minum);
        }else{
            b[minum]=3;
            c[3][++cnt[3]].num=minum;
            c[3][cnt[3]].score=a[minum][3];
            cnttrue[3]++;
            judge(3,minum);
        }
    }else if(d==2){
        ll cha=cnttrue[2]-n/2;
        if(cha<=0) return ;
        sort(c[2]+1,c[2]+cnt[2],cmp);
        for(int j=1;j<=cnt[2];j++){
            if(c[2][j].f==false) continue;
            ll i=c[2][j].num;
            ll ma=max(a[i][1],a[i][3]);
            if(ma-a[i][2]>=0||a[x][2]+ma-a[i][2]>=0){
                cha--;
                cnttrue[2]--;
                c[2][j].f=false;
                if(ma==a[i][1]){
                    b[i]=1;
                    c[1][++cnt[1]].num=i;
                    c[1][cnt[1]].score=a[i][1];
                    cnttrue[1]++;
                    judge(1,i);
                }else {
                    b[i]=3;
                    c[3][++cnt[3]].num=i;
                    c[3][cnt[3]].score=a[i][3];
                    cnttrue[3]++;
                    judge(3,i);
                }
            }else continue;
            if(cha==0) return ;
        }
        ll mi=0x3f3f3f3f,minum,minum2;
        for(int j=1;j<=cnt[2];j++){
            if(c[2][j].f==false) continue;
            ll i=c[2][j].num;
            if(a[x][2]-a[i][2]+max(a[i][1],a[i][3])<mi){
                mi=a[x][2]-a[i][2]+max(a[i][1],a[i][3]);
                minum=i;
                minum2=j;
            }
        }
        c[2][minum2].f==false;
        if(a[minum][1]>=a[minum][3]){
            b[minum]=1;
            c[1][++cnt[1]].num=minum;
            c[1][cnt[1]].score=a[minum][1];
            cnttrue[1]++;
            judge(1,minum);
        }else{
            b[minum]=3;
            c[3][++cnt[3]].num=minum;
            c[3][cnt[3]].score=a[minum][3];
            cnttrue[3]++;
            judge(3,minum);
        }
    }else{
        ll cha=cnttrue[3]-n/2;
        if(cha<=0) return ;
        sort(c[3]+1,c[3]+cnt[3],cmp);
        for(int j=1;j<=cnt[3];j++){
            if(c[2][j].f==false) continue;
            ll i=c[3][j].num;
            ll ma=max(a[i][2],a[i][1]);
            if(ma-a[i][3]>=0||a[x][3]+ma-a[i][3]>=0){
                cha--;
                cnttrue[3]--;
                c[3][j].f==false;
                if(ma==a[i][2]){
                    b[i]=2;
                    c[2][++cnt[2]].num=i;
                    c[2][cnt[2]].score=a[i][2];
                    cnttrue[2]++;
                    judge(2,i);
                }else {
                    b[i]=1;
                    c[1][++cnt[1]].num=i;
                    c[1][cnt[1]].score=a[i][1];
                    cnttrue[1]++;
                    judge(1,i);
                }
            }else continue;
            if(cha==0) return ;
        }
        ll mi=0x3f3f3f3f,minum,minum2;
        for(int j=1;j<=cnt[3];j++){
            if(c[2][j].f==false) continue;
            ll i=c[3][j].num;
            if(a[x][3]-a[i][1]+max(a[i][2],a[i][3])<mi){
                mi=a[x][1]-a[i][1]+max(a[i][2],a[i][3]);
                minum=i;
                minum2=j;
            }
        }
        c[3][minum2].f==false;
        if(a[minum][2]>=a[minum][1]){
            b[minum]=2;
            c[2][++cnt[2]].num=minum;
            c[2][cnt[2]].score=a[minum][2];
            cnttrue[2]++;
            judge(2,minum);
        }else{
            b[minum]=1;
            c[1][++cnt[1]].num=minum;
            c[1][cnt[1]].score=a[minum][1];
            cnttrue[1]++;
            judge(1,minum);
        }
    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        memset(cnttrue,0,sizeof(cnttrue));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            ll x=a[i][1],y=a[i][2],z=a[i][3];
            ll ma=max(x,max(y,z));
            if(ma==x){
                b[i]=1;
                c[1][++cnt[1]].num=i;
                c[1][cnt[1]].score=ma;
                cnttrue[1]++;
                if(cnt[1]>n/2) judge(1,i);
            }else if(ma==y){
                b[i]=2;
                c[2][++cnt[2]].num=i;
                c[2][cnt[2]].score=ma;
                cnttrue[2]++;
                if(cnttrue[2]>n/2) judge(2,i);
                //cout<<cnt[2]<<endl;
            }else{
                b[i]=3;
                c[3][++cnt[3]].num=i;
                cnttrue[3]++;
                c[3][cnt[3]].score=ma;
                if(cnttrue[3]>n/2) judge(3,i);
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[i][b[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
