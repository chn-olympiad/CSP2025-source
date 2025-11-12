#include<bits/stdc++.h>
using namespace std;
#define ll long long

void pre(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
}

const int N=201;
const int NN=1e5+5;
int t,n,nn;
ll a[N][3],f[N][N][N];
ll ans=0;


bool isNotA=0,isNotB=0;
void init(){
    cin>>n;
    nn=n/2;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++){
            cin>>a[i][j];
        }

        if(a[i][1]!=0) isNotA=1;
        if(a[i][2]!=0) isNotA=isNotB=1;
    }

    ans=0;
    memset(f,0,sizeof(f));
}

void DP(){
    for(int now=1;now<=n;now++)
    for(int i=nn;i>=0;i--)
    for(int j=nn;j>=0;j--)
    for(int k=nn;k>=0;k--)
    {
        if(i>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[now][0]);
        if(j>0)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[now][1]);
        if(k>0)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[now][2]);
        if(now==n) ans=max(ans,f[i][j][k]);
    }
}

void solveA(){
    int tmp[n];
    for(int i=0;i<n;i++) tmp[i]=a[i+1][0];
    sort(tmp,tmp+n);
    for(int i=n-1;i>=nn+1-1;i--) ans+=tmp[i];
}

void solveB(){
    priority_queue <int> cost;// a -> b
    for(int i=1;i<=n;i++){
        if(cost.size()<nn){
            cost.push(a[i][1]-a[i][0]);
            ans+=a[i][0];
        }
        else{
            if(a[i][0]-a[i][1] + cost.top() > 0){
                ans+=a[i][0]-a[i][1] + cost.top();
                cost.pop();
                cost.push(a[i][1]-a[i][0]);
            }
        }
    }
}
int main(){
    pre();
    cin>>t;
    while(t--){
        init();
        if(n<=200) DP();
        else{
            if(!isNotA){
                solveA();
            }
            else if(!isNotB){
                solveB();
            }
            else{
                cout<<"11451419"<<endl;
                return 0;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
