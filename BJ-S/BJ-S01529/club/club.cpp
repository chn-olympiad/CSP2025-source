#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
const int M=1e3+7;
const int INF=0x3f3f3f3f;
//time :O(NlogN)
//space:O(N)

struct ppl
{
    ll n,x,y,z;
};

inline bool cmp1(ppl lmz, ppl lzy)
{
    if(lmz.x<lmz.y)swap(lmz.x,lmz.y);
    if(lmz.x<lmz.z)swap(lmz.x,lmz.z);
    if(lmz.y<lmz.z)swap(lmz.y,lmz.z);
    if(lzy.x<lzy.y)swap(lzy.x,lzy.y);
    if(lzy.x<lzy.z)swap(lzy.x,lzy.z);
    if(lzy.y<lzy.z)swap(lzy.y,lzy.z);
    return (lmz.x-lmz.y) > (lzy.x-lzy.y);
}

/*
inline bool cmp2(ppl lmz, ppl lzy)
{
    return max(lmz.y,lmz.z) > max(lzy.y,lzy.z);
}
*/

int T;
int n;
ppl a[N];
ll ans;
bool v[N];
ll cx=0,cy=0,cz=0;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("club.in" ,"r",stdin );
    freopen("club.out","w",stdout);
    cin>>T;
    ll tmp;
    while(T--)
    {
        /*INIT*/ans=0;
        cin>>n;
        //ll tmp;
        for(int i=1;i<=n;i++)
        {
            a[i].n=i;
            cin>>tmp;
            a[i].x=tmp;
            cin>>tmp;
            a[i].y=tmp;
            cin>>tmp;
            a[i].z=tmp;
        }
        sort(a+1,a+n+1,cmp1);
        /*INIT*/cx=0,cy=0,cz=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].x>=a[i].y and a[i].x>=a[i].z)
            {
                if(cx<n/2) ans+=a[i].x,++cx; else
                if(a[i].y>=a[i].z) ans+=a[i].y,++cy; else
                ans+=a[i].z,++cz;
            }else
            if(a[i].y>=a[i].z)
            {
                if(cy<n/2) ans+=a[i].y,++cy; else
                if(a[i].x>=a[i].z) ans+=a[i].x,++cx; else
                ans+=a[i].z,++cz;
            }else
            {
                if(cz<n/2) ans+=a[i].z,++cz; else
                if(a[i].y>=a[i].x) ans+=a[i].y,++cy; else
                ans+=a[i].x,++cx;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

/*
=====TODO=====
[V] subtest init
[V] long long
[1] freopen triple chaeck
[V] cornercase
g++ lmz.cpp -o lmz -Wall
[V] estimate time and space
rp++
[V] save before run

*/
