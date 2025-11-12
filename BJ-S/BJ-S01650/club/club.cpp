#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;

struct node{
    int val;
    int id;
}s[N];
int totn;
int nedcls,numcls;
int tcnt[N];
int T,n,ans,a[N][3],c[N];
bool cmp(node x,node y){
    return x.val>y.val;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        tcnt[1]=tcnt[2]=tcnt[3]=0;
        ans=nedcls=numcls=totn=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
            if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1])c[i]=1,tcnt[1]++;
            else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2])c[i]=2,tcnt[2]++;
            else c[i]=3,tcnt[3]++;
            ans+=a[i][c[i]];
        }  
        for(int i=1;i<=3;i++){
            if(tcnt[i]>(n/2)){
                numcls=i;
                nedcls=tcnt[i]-(n/2);
                break;    
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i]==numcls){
                s[++totn].id=i;
                int mxv=0;
                for(int j=1;j<=3;j++){
                    if(j==numcls)continue;
                    mxv=max(mxv,a[i][j]);
                }
                s[totn].val=mxv-a[i][numcls];
            }
        }
        sort(s+1,s+totn+1,cmp);
        for(int i=1;i<=nedcls;i++)ans+=s[i].val;
        printf("%d\n",ans);
    }
    return 0;
}