#include<bits/stdc++.h>
using namespace std;
int a[100010];
int d[110][110];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int tmp=a[1];
    sort(a+1,a+n*m+1,cmp);
    int t;
    for(int i=1;i<=n*m;i++){
        if(tmp==a[i]){
            t=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j]=-1;
        }
    }
    int i=1,j=1;
    for(int x=1;x<=n*m;x++){
        d[i][j]=x;
        if(x==t){
            cout<<j<<" "<<i;
            return 0;
        }
        if(d[i+1][j]==-1){
            i+=1;
            continue;
        }
        if(d[i-1][j]==-1){
            i-=1;
            continue;
        }
        if(d[i+1][j]!=-1&&d[i-1][j]!=-1){
            j+=1;
            continue;
        }
    }
    cout<<n<<m<<endl;
    return 0;
}
