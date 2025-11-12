#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int num[N][N];
int a[N];
int totle;
#define ret return
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;totle=n*m;
    // cout<<"n: "<<n<<" m: "<<m<<" totle: "<<totle<<'\n';
    for(int i=1;i<=totle;i++) cin>>a[i];
    int r= a[1];
    sort(a+1,a+totle+1,cmp);
    // for(int i: a) if(a[i]) cout<<a[i]<<'\n';
    bool f=true;
    // 令f=true的时候，从上到下填充，反之，则反
    for(int i=0;i<m;i++)
    {
        // for(int j=1;j<=n;j++)
        // {
        //     num[i][j]=a[n*i+j];
        //     // cout<<"i: "<<i<<" j: "<<j<<" num[i][j]: "<<num[i][j]<<" n*i+j: "<<n*i+j<<" a[n*i+j]: "<<a[n*i+j]<<'\n';
        // }
        if(f)
        {
            for(int j=1;j<=n;j++) num[i][j]=a[n*i+j];
        }
        else
        {
            int tmp=1;
            for(int j=n;j>=1;j--) {num[i][j]=a[n*i+tmp];tmp++;}
        }
        f=!f;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++) {
            if(r== num[i][j])
            {
                cout<<i+1<<" "<<j<<'\n';ret 0;
            }
        }
    }
    ret 0;
}