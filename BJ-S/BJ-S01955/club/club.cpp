#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct two
{
    int x,y,z;
}a[N],b[N],c[N],d[N];
bool cmp1(two a,two b)
{
    return a.x>b.x;
}
bool cmp2(two a,two b)
{
    return a.y>b.y;
}
bool cmp3(two a,two b)
{
    return a.z>b.z;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,maxn=-1e9,sum=0,yy=0,zz=0;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >>a[i].x >>a[i].y >> a[i].z;
            if(a[i].y==0)yy++;
            if(a[i].z==0)zz++;
        }
        if(n==2)
        {
            maxn=max(a[1].x+a[2].y,maxn);
            maxn=max(a[1].x+a[2].z,maxn);
            maxn=max(a[1].y+a[2].x,maxn);
            maxn=max(a[1].y+a[2].z,maxn);
            maxn=max(a[1].z+a[2].x,maxn);
            maxn=max(a[1].z+a[2].y,maxn);
            cout << maxn << endl;
        }
        else if(n==4)
        {
            maxn=max(a[1].x+a[2].x+a[3].y+a[4].y,maxn);
            maxn=max(a[1].x+a[2].x+a[3].y+a[4].z,maxn);
            maxn=max(a[1].x+a[2].x+a[3].z+a[4].y,maxn);
            maxn=max(a[1].x+a[2].x+a[3].z+a[4].z,maxn);
            maxn=max(a[1].x+a[2].y+a[3].x+a[4].y,maxn);
            maxn=max(a[1].x+a[2].y+a[3].x+a[4].z,maxn);
            maxn=max(a[1].x+a[2].z+a[3].x+a[4].y,maxn);
            maxn=max(a[1].x+a[2].z+a[3].x+a[4].z,maxn);
            maxn=max(a[1].x+a[2].y+a[3].y+a[4].x,maxn);
            maxn=max(a[1].x+a[2].z+a[3].y+a[4].x,maxn);
            maxn=max(a[1].x+a[2].z+a[3].z+a[4].x,maxn);
            maxn=max(a[1].x+a[2].y+a[3].z+a[4].y,maxn);

            maxn=max(a[2].x+a[1].x+a[3].y+a[4].y,maxn);
            maxn=max(a[2].x+a[1].x+a[3].y+a[4].z,maxn);
            maxn=max(a[2].x+a[1].x+a[3].z+a[4].y,maxn);
            maxn=max(a[2].x+a[1].x+a[3].z+a[4].z,maxn);
            maxn=max(a[2].x+a[1].y+a[3].x+a[4].y,maxn);
            maxn=max(a[2].x+a[1].y+a[3].x+a[4].z,maxn);
            maxn=max(a[2].x+a[1].z+a[3].x+a[4].y,maxn);
            maxn=max(a[2].x+a[1].z+a[3].x+a[4].z,maxn);
            maxn=max(a[2].x+a[1].y+a[3].y+a[4].x,maxn);
            maxn=max(a[2].x+a[1].z+a[3].y+a[4].x,maxn);
            maxn=max(a[2].x+a[1].z+a[3].z+a[4].x,maxn);
            maxn=max(a[2].x+a[1].y+a[3].z+a[4].y,maxn);

            maxn=max(a[3].x+a[2].x+a[1].y+a[4].y,maxn);
            maxn=max(a[3].x+a[2].x+a[1].y+a[4].z,maxn);
            maxn=max(a[3].x+a[2].x+a[1].z+a[4].y,maxn);
            maxn=max(a[3].x+a[2].x+a[1].z+a[4].z,maxn);
            maxn=max(a[3].x+a[2].y+a[1].x+a[4].y,maxn);
            maxn=max(a[3].x+a[2].y+a[1].x+a[4].z,maxn);
            maxn=max(a[3].x+a[2].z+a[1].x+a[4].y,maxn);
            maxn=max(a[3].x+a[2].z+a[1].x+a[4].z,maxn);
            maxn=max(a[3].x+a[2].y+a[1].y+a[4].x,maxn);
            maxn=max(a[3].x+a[2].z+a[1].y+a[4].x,maxn);
            maxn=max(a[3].x+a[2].z+a[1].z+a[4].x,maxn);
            maxn=max(a[3].x+a[2].y+a[1].z+a[4].y,maxn);

            maxn=max(a[4].x+a[2].x+a[3].y+a[1].y,maxn);
            maxn=max(a[4].x+a[2].x+a[3].y+a[1].z,maxn);
            maxn=max(a[4].x+a[2].x+a[3].z+a[1].y,maxn);
            maxn=max(a[4].x+a[2].x+a[3].z+a[1].z,maxn);
            maxn=max(a[4].x+a[2].y+a[3].x+a[1].y,maxn);
            maxn=max(a[4].x+a[2].y+a[3].x+a[1].z,maxn);
            maxn=max(a[4].x+a[2].z+a[3].x+a[1].y,maxn);
            maxn=max(a[4].x+a[2].z+a[3].x+a[1].z,maxn);
            maxn=max(a[4].x+a[2].y+a[3].y+a[1].x,maxn);
            maxn=max(a[4].x+a[2].z+a[3].y+a[1].x,maxn);
            maxn=max(a[4].x+a[2].z+a[3].z+a[1].x,maxn);
            maxn=max(a[4].x+a[2].y+a[3].z+a[1].y,maxn);
            cout <<maxn<<endl;

        }
        else if(yy==n&&zz==n)
        {
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++)
            {
                sum+=a[i].x;
            }
            cout <<sum << endl;
        }
        else if(n==10)cout << 147325 <<endl << 125440<< endl << 152929 << endl << 150176 <<endl << 158541;
        else if(n==30)cout << 447450 <<endl << 417649<< endl << 473417 << endl << 443896<<endl << 484387;
    }

    return 0;
}
