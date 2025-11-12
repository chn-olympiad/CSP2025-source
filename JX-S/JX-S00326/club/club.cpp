#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5];
int sa,sb,sc,so;
int A[N],B[N],C[N],O[N];
//
bool cmpa(int x,int y)
{
    if((a[y][1]+max(a[x][2],a[x][3]))==(a[x][1]+max(a[y][2],a[y][3])))
        return a[x][1]>a[y][1];
    else
        return (a[y][1]+max(a[x][2],a[x][3]))<(a[x][1]+max(a[y][2],a[y][3]));
}
bool cmpb(int x,int y)
{
    if((a[y][2]+max(a[x][1],a[x][3]))==(a[x][2]+max(a[y][1],a[y][3])))
        return a[x][2]>a[y][2];
    else
        return (a[y][2]+max(a[x][1],a[x][3]))<(a[x][2]+max(a[y][1],a[y][3]));
}
bool cmpc(int x,int y)
{
    if((a[y][3]+max(a[x][1],a[x][2]))==(a[x][3]+max(a[y][1],a[y][2])))
        return a[x][3]>a[y][3];
    else
        return (a[y][3]+max(a[x][1],a[x][2]))<(a[x][3]+max(a[y][1],a[y][2]));
}
/*
bool cmpa(int x,int y)
{
    if(max(a[x][2],a[x][3])==max(a[y][2],a[y][3]))
        return a[x][1]>a[y][1];
    else
        return max(a[x][2],a[x][3])<max(a[y][2],a[y][3]);
}
bool cmpb(int x,int y)
{
    if(max(a[x][1],a[x][3])==max(a[y][1],a[y][3]))
        return a[x][2]>a[y][2];
    else
        return max(a[x][1],a[x][3])<max(a[y][1],a[y][3]);
}
bool cmpc(int x,int y)
{
    if(max(a[x][1],a[x][2])==max(a[y][1],a[y][2]))
        return a[x][3]>a[y][3];
    else
        return max(a[x][1],a[x][2])<max(a[y][1],a[y][2]);
}
*/
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        sa=sb=sc=so=0;
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
            {
                A[++sa]=i;
            }
            else if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3])
            {
                B[++sb]=i;
            }
            else if (a[i][3]>a[i][1]&&a[i][3]>a[i][2])
            {
                C[++sc]=i;
            }
            else
            {
                O[++so]=i;
            }
        }
        if(sa>n/2||sb>n/2||sc>n/2)
        {
            sort(A+1,A+sa+1,cmpa);
            sort(B+1,B+sb+1,cmpb);
            sort(C+1,C+sc+1,cmpc);
            if(sa>n/2)
            {
                for(int i=n/2+1;i<=sa;i++)
                {
                    O[++so]=A[i];
                    a[A[i]][1]=INT_MIN;
                }
                sa=n/2;
            }
            if(sb>n/2)
            {
                for(int i=n/2+1;i<=sb;i++)
                {
                    O[++so]=B[i];
                    a[B[i]][2]=INT_MIN;
                }
                sb=n/2;
            }
            if(sc>n/2)
            {
                for(int i=n/2+1;i<=sc;i++)
                {
                    O[++so]=C[i];
                    a[C[i]][3]=INT_MIN;
                }
                sc=n/2;
            }
        }
        int ans=0;
        for(int i=1;i<=sa;i++)
        {
            ans+=a[A[i]][1];
        }
        for(int i=1;i<=sb;i++)
        {
            ans+=a[B[i]][2];
        }
        for(int i=1;i<=sc;i++)
        {
            ans+=a[C[i]][3];
        }
        for(int i=1;i<=so;i++)
        {
            ans+=max(a[O[i]][1],max(a[O[i]][2],a[O[i]][3]));
        }
        cout << ans;
    }
    return 0;
}
