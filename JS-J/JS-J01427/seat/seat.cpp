#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const int MAXN=0;
int n,m,al,r,cnt;
vector<int> v;
int main ()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    al=m*n;
    cin>>r;
    v.pb(r);
    fore(i,1,al)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    fore(i,0,al)
    {
        if(v[i]==r)
        {
            cnt=i;
            break;
        }
    }
    int a=1,b=1;
    bool flag=0;
    while(cnt--)
    {
        if(flag==0)
        {
            if(a==n)
            {
                b++;
                flag=1;
            }
            else
            {
                a++;
            }
        }
        else
        {
            if(a==1)
            {
                b++;
                flag=0;
            }
            else
            {
                a--;
            }
        }
    }
    cout<<b<<" "<<a;
    return 0;
}
