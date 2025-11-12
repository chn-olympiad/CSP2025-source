#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=5050;
long long ans;
int a[maxn],n;
bool used[maxn];
bool fi=1;


void bfs(int cnt,int sum,int lar,int lari){
    if(cnt==n+1){
        if(!fi) return;
        else if(lar*2<sum){
            ans++;
            ans%=mod;
            fi=0;
        }
        return;

    }
     if(cnt>3){
        if(lar*2<sum){
            ans++;
            ans%=mod;
        }
     }

            for(int i=1;i<=n;i++){
            if(used[i]||i<=lari) continue;
            used[i]=1;
            bfs(cnt+1,sum+a[i],max(lar,a[i]),max(lari,i));
            used[i]=0;
        }
}

bool flag=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int bes=0;
    int sum1=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum1+=a[i];
        bes=max(bes,a[i]);
        if(a[i]!=1) flag=0;
    }
    sort(a+1,a+n+1);
   if(n<2) cout<<0;
   if(n==3){
    if(bes*2<sum1) cout<<1;
    else cout<<0;
   }
   if(n>3&&n<=20){
    bfs(1,0,0,0);
    cout<<ans;
   }
   ans=0;


   if(flag&&n>20){
    for(int i=3;i<=n;i++){
        int c=n-i;
        int m=n;
        long long j=1;
        for(int k=1;k<=c;k++){
            j*=m;
            j/=k;
            m--;
            j%=mod;
        }
        ans+=j;
        ans%=mod;
    }
    cout<<ans;
   }

   fclose(stdin);
   fclose(stdout);
    return 0;
}
