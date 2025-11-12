#include<cstdio>
#include<algorithm>
using namespace std;
#define M 100005
struct node
{
    int v,id;
  
}a[M][4],b[M];
int cnt[M];
/*void swa(node &a,node &b)
{
    node t;
    t.v=a.v;
    t.id=a.id;
    a.v=b.v;
    a.id=b.id;
    b.id=t.id;
    b.v=t.v;
}*/
bool cmp(node x,node y)
{return x.v<y.v;}
void solv()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            scanf("%d",&a[i][j].v);
            a[i][j].id=j;//printf("%d ",a[i][j].v);
        }
        if(a[i][1].v<a[i][2].v)swap(a[i][1].v,a[i][2].v),swap(a[i][1].id,a[i][2].id)/*,printf("a")*/;
        //else{}
        if(a[i][1].v<a[i][3].v)swap(a[i][1].v,a[i][3].v),swap(a[i][1].id,a[i][3].id)/*,printf("c")*/;
        //else{}
        if(a[i][2].v<a[i][3].v)swap(a[i][2].v,a[i][3].v),swap(a[i][2].id,a[i][3].id)/*,printf("b")*/;
        //else{}
        
        //puts("");
    }/*for(int i=1;i<=n;i++)
    {
        b[i].v=a[i][1].v;
        b[i].id=i;
    }sort(b+1,b+n+1,cmp);*///printf("d");
    for(int i=1;i<=3;i++)cnt[i]=0;
    for(int i=1;i<=n;i++)
    {//for(int j=1;j<=3;j++)printf("%d ",a[i][j].v);
        cnt[a[i][1].id]++;
    }for(int j=1;j<=3;j++)
    {
        if ((cnt[j]>n/2))
        {
            for(int i=1;i<=n;i++)
            {
                b[i].v=a[i][1].v-a[i][2].v;
                b[i].id=i;
            }sort(b+1,b+n+1,cmp);
            //printf("%d\n",cnt[j]-n/2);
            for(int k=1,op=1;k<=n&&op<=cnt[j]-n/2;k++)
            {//printf("k%d",k);
                if(a[b[k].id][1].id==j)a[b[k].id][1].v=a[b[k].id][2].v,op++;
                //a[b[k].id][2].v=a[b[k].id][3].v;
                /*for(int l=1;l<=3;l++)printf("%d ",a[b[k].id][l].v);
                cnt[a[b[k].id][1].id]--;
                cnt[a[b[k].id][2].id]++;
                printf("k %d",k);*/
            }
            //break;
        }
        
    }/*for(int j=1;j<=3;j++)
    {
        if ((cnt[j]>n/2))
        {
            for(int i=1;i<=n;i++)
            {
                b[i].v=a[i][1].v-[i][2].v;
                b[i].id=i;
            }sort(b+1,b+n+1,cmp);
            for(int k=1;k<=cnt[j]-n/2;k++)
            {
                a[b[k].id][1].v=a[b[k].id][2].v;
                a[b[k].id][2].v=a[b[k].id][3].v;
                cnt[a[b[k].id][1].id]--;
                cnt[a[b[k].id][2].id]++;
            }break;
        }
        
    }*/for(int i=1;i<=n;i++)
    {ans+=a[i][1].v;/*printf("%d ",a[i][1].v);*/}printf("%d\n",ans);
}int main()
{freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)solv();
    return 0;
}