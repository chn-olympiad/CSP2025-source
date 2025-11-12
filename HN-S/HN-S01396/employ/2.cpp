#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int mod=998244353;
string a;
int n,m;
int c[N];
void add(int &x,int y){x=x+y>=mod?x+y-mod:x+y;}
namespace work1
{
    int p[N];
    int main()
    {
        for(int i=1;i<=n;i++) p[i]=i;
        int ans=0;
        do
        {
            int now=0;
            for(int i=1;i<=n;i++)
                if(a[i-1]=='0'||now>=c[p[i]])
                    now++;
            ans+=now<=n-m;
        }while(next_permutation(p+1,p+1+n));
        cout<<ans;
    }
}
signed main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n<=18) return work1::main();
    return 0;
}