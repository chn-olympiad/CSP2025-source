#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
using namespace std;
struct node{int x,y,z;} a[300005];
int b[100004][3];
bitset<100004> c;
bool cmp(node x,node y)
{
    // if (x.x==y.x)
    // {
    //     return (b[x.y][0]+b[x.y][1]+b[x.y][2])<(b[y.y][0]+b[y.y][1]+b[y.y][2]);
    // }
    return x.x>y.x;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        loop(i,n)
        {
            cin >> b[i][0] >> b[i][1] >> b[i][2];
            a[(i-1)*3+1]={b[i][0]-max(b[i][1],b[i][2]),i,0};
            a[(i-1)*3+2]={b[i][1]-max(b[i][0],b[i][2]),i,1};
            a[(i-1)*3+3]={b[i][2]-max(b[i][1],b[i][0]),i,2};
            c[i]=0;
        }
        sort(a+1,a+n*3+1,cmp);
        int ans=0,cnt[3]={0,0,0},t=n/2;
        loop(i,n*3)
        {
            if (!c[a[i].y]&&cnt[a[i].z]<t)
				ans+=b[a[i].y][a[i].z],c[a[i].y]=1,cnt[a[i].z]++;
        }
        cout << ans << endl;
    }
    return 0;
}
