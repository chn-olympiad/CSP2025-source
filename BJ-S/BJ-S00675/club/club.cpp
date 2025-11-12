#include<bits/stdc++.h>
using namespace std;
int big[100010],o,p,q;
int l1[100010],l2[100010],l3[100010];
struct node
{
    int x=0,y=0,z=0;
};
node a[110][100100];
int  dfs(int dao,int geshu,int cnt)
{
    //到就是当前组数
    int k1=0,k2=0,k3=0,r=cnt;
    if(geshu==big[dao])return cnt;
    if(o<big[dao]/2)
    {
        cnt+=a[dao][geshu].x;
        o++;
        //cout<<"zuo"<<' '<<geshu<<' '<<cnt<<endl;
        k1=dfs(dao,geshu+1,cnt);
        o--;
        cnt=r;
    }
    if(p<big[dao]/2)
    {
        cnt+=a[dao][geshu].y;
        p++;
        //cout<<"zhong"<<' '<<geshu<<' '<<cnt<<endl;
        k2=dfs(dao,geshu+1,cnt);
        p--;
        cnt=r;
    }
    if(q<big[dao]/2)
    {
        cnt+=a[dao][geshu].z;
        q++;
        //cout<<"you"<<' '<<geshu<<' '<<cnt<<endl;
        k3=dfs(dao,geshu+1,cnt);
        q--;
        cnt=r;
    }
    cnt=max(max(k1,k2),k3);
    return cnt;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int bign;
    cin>>bign;
    for(int i=0;i<bign;i++)
    {
        cin>>big[i];
        for(int j=0;j<big[i];j++)
        {
            cin>>a[i][j].x>>a[i][j].y>>a[i][j].z;
        }
    }
    for(int i=0;i<bign;i++)
    {
        cout<<dfs(i,0,0)<<endl;
        o=0;
        p=0;
        q=0;
    }
    return 0;
}