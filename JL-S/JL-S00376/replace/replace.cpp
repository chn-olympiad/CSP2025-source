#include <bits/stdc++.h>
using namespace std;
struct node
{
    string y1,y2;
}a[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        cin>>a[i].y1>>a[i].y2;
    while(q--)
    {
        string t1,t2;
        int ans=0;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=t1.size()-a[i].y1.size();j++)
            {
                if(t1.size()<a[i].y1.size())
                    break;
                int l=0,r=j;
                while(a[i].y1[l]==t1[r]&&l<a[i].y1.size())
                    l++,r++;
                if(l!=a[i].y1.size())
                    continue;
                l=0;
                string res=t1;
                for(int k=j;k<j+a[i].y1.size();k++)
                    res[k]=a[i].y2[l++];
                if(res==t2)
                    ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
