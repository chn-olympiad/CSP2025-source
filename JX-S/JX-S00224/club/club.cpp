#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int b,a[N][4],n,s[6],sum,d[4];
bool road[N][4]={0};
int dfs(int);
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
        int t;
        cin>>t;
        for(int T=1;T<=t;T++)
        {sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
        {
         cin>>a[i][j];
        }
        s[T]=dfs(1);
        }
    for(int T=1;T<=t;T++)
            cout<<s[T]<<endl;
            return 0;
}
int dfs (int k)
{
   int x=n;
   if(x==k){
        b=max(a[k][1],a[k][2]);
   b=max(b,a[k][3]);
   sum+=b;
   b=0;
    return sum;
   }
   else dfs(k+1);
   b=max(a[k][1],a[k][2]);
   b=max(b,a[k][3]);
   sum+=b;
   b=0;
}
