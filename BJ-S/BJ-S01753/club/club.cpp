/*
 ____
/    \  This is a sugar bean.
\____/  Sugar bean don't judge your flaws.
May the God of Sugar Bean bless all OIers!
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100005
LL read(){
    char ch=getchar();
    int p=1;
    LL x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')p=-p;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*p;
}
void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}

struct node{
    LL val[5];
}a[N];
bool low(LL a,LL b){
    return a>b;
}
LL cnt[5];
bool cmp1(node a,node b){
    return max(a.val[2],a.val[3])-a.val[1]>max(b.val[2],b.val[3])-b.val[1];
}
bool cmp2(node a,node b){
    return max(a.val[1],a.val[3])-a.val[2]>max(b.val[1],b.val[3])-b.val[2];
}
bool cmp3(node a,node b){
    return max(a.val[2],a.val[1])-a.val[3]>max(b.val[2],b.val[1])-b.val[3];
}
vector<node>join[5];
void init(){
    join[1].clear();
    join[2].clear();
    join[3].clear();
    memset(cnt,0,sizeof cnt);
}
void solve(){
    init();
    LL n,ans=0;
    n=read();
    for(LL i=1;i<=n;i++){
        LL maxn=0,maxpos=1;
        for(LL j=1;j<=3;j++){
            a[i].val[j]=read();
            if(maxn<a[i].val[j]){
                maxn=a[i].val[j];
                maxpos=j;
            }
        }
        ans+=maxn;
        cnt[maxpos]++;
        join[maxpos].push_back(a[i]);
    }
/*
    printf("join:\n");
    for(LL i=1;i<=3;i++){
        printf("%lld %lld : ",i,cnt[i]);
        for(LL j=0;j<join[i].size();j++)printf("%lld %lld %lld , ",join[i][j].val[1],join[i][j].val[2],join[i][j].val[3]);
        printf("\n");
    }
*/
    for(LL k=1;k<=3;k++){
        //printf("k:%lld\n",k);
        if(cnt[k]>n/2){
            //printf("out %lld\n",k);
            if(k==1)sort(join[1].begin(),join[1].end(),cmp1);
            else if(k==2)sort(join[2].begin(),join[2].end(),cmp2);
            else if(k==3)sort(join[3].begin(),join[3].end(),cmp3);
            /*
            printf("sort : ");
            for(LL i=0;i<join[k].size();i++)
                printf("%lld %lld %lld , ",join[k][i].val[1],join[k][i].val[2],join[k][i].val[3]);
            */
            for(LL i=0;i<cnt[k]-n/2;i++){
                ans+=max(join[k][i].val[k%3+1],join[k][i].val[(k%3+1)%3+1])-join[k][i].val[k];
                //printf("add %lld %lld\n",max(join[k][i].val[k%3+1],join[k][i].val[(k%3+1)%3+1]),max(join[k][i].val[k%3+1],join[k][i].val[(k%3+1)%3+1])-join[k][i].val[k]);
            }
            write(ans);
            putchar('\n');
            return ;
        }
    }
    write(ans);
    putchar('\n');
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    LL T;
    T=read();
    while(T--){
        solve();
    }
    return 0;
}
/*
5
4
8 3 8
4 4 5
0 2 6
0 1 8
*/
