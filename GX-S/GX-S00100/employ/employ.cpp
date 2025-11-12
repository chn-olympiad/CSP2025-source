#include<iostream>
#include<algorithm>
using namespace std;
constexpr int Mn=503;
char S[Mn];
int c[Mn],n,m,p[Mn],i,j,y,w;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>S+1;
    for(i=1;i<=n;i++)cin>>c[i];
    for(i=1;i<=n;i++)p[i]=i;
    do
    {
        w=0;
        for(i=1;i<=n;i++)
        {
            if(S[i]=='1'&&(i-1-w)<c[p[i]])w++;
            if(w>=m)
            {
                y++;
                break;
            }
            if(w+n-i<m)break;
        }
    }
    while(next_permutation(p+1,p+n+1));
    cout<<y;
    return 0;
}
