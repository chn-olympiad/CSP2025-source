#include<bits/stdc++.h>
using namespace std;
struct club
{
    int s[3];
}cl[100005];
int t,n,ans;
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%d%d%d",&cl[j].s[0],&cl[j].s[1],&cl[j].s[2]);
            if(max(cl[j].s[0],max(cl[j].s[1],cl[j].s[2]))==cl[j].s[0])ans+=cl[j].s[0];
            else if(max(cl[j].s[0],max(cl[j].s[1],cl[j].s[2]))==cl[j].s[1])ans+=cl[j].s[1];
            else ans+=cl[j].s[2];
        }
        printf("%d\n",ans);
    }
    return 0;
}
