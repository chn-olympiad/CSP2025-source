#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
int T,n,a[MAXN][4],b[MAXN],p[4];
vector<int>t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        p[1]=p[2]=p[3]=0;
        t.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",a[i]+1,a[i]+2,a[i]+3);
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])p[b[i]=1]++;
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])p[b[i]=2]++;
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])p[b[i]=3]++;
        }
        if(p[1]<=n/2&&p[2]<=n/2&&p[3]<=n/2){
            for(int i=1;i<=n;i++)ans+=max(max(a[i][1],a[i][2]),a[i][3]);
            printf("%d\n",ans);
        }
        else{
            int tmp;
            if(p[1]>n/2)tmp=1;
            else if(p[2]>n/2)tmp=2;
            else tmp=3;
            for(int i=1;i<=n;i++){
                ans+=max(max(a[i][1],a[i][2]),a[i][3]);
                if(b[i]==tmp)t.push_back(a[i][tmp]-max(a[i][tmp%3+1],a[i][(tmp+1)%3+1]));
            }
            sort(t.begin(),t.end());
            int top=0;
            while(p[tmp]>n/2)p[tmp]--,ans-=t[top++];
            printf("%d\n",ans);
        }
    }
    return 0;
}
