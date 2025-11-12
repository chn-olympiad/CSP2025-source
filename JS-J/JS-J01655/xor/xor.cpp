#include<bits/stdc++.h>
using namespace std;
int a[100010];

struct Node
{
    int l,r;

}node[1000100];
bool cmp(Node x,Node y)
{
    return x.r< y.r;
}
int top;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    if(n >1000&&k<=1)
    {
        int sum = 0;
        if(k == 1)
        {
            for(int i = 1;i<= n;i++)
            {

                scanf("%d",&a[i]);
                sum+= a[i];
            }
            printf("%d\n",sum);
        }
        else
        {
            int t = 0;
            for(int i = 1;i<= n;i++)
            {
                scanf("%d",&a[i]);
                if(a[i] == 0)
                {
                    sum+= 1;
                    t = 0;
                }
                else
                {
                    sum+= (t+ 1)/2;
                    (++t)%= 2;
                }
            }
            printf("%d\n",sum);
        }
    }
    for(int i = 1;i<= n;i++)
    {
         scanf("%d",&a[i]);
        a[i] = a[i]^a[i-1];
    }
    for(int i = 1;i<= n;i++)
    {
        for(int  j = i;j<= n;j++){ if((a[i-1]^a[j]) == k){
        node[++top] = {i,j};
        if(n>10000)break;}
        }
    }
    sort(node+1,node+top+1,cmp);
    int ans = 0;
    int R = 0;
    for(int i = 1;i<= top;i++)
    {
        if(node[i].l> R)
        {
            ans ++;
            R = node[i].r;
        }
    }
    printf("%d\n",ans);
    return 0;
}
