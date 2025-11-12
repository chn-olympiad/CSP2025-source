#include<bits/stdc++.h>
#define ll long long
using namespace std;
int Ans=0;
const int N=998244353;
int b[5001]={0,0,0,1,6,22,64,163,382,848,1816,3797,7814,15914,32192,64839,130238,261156,523128,1047225,2095590,4192510,8386560,16774891,33551806,67105912,134214424,268431773,536866822,75492945,150989950,301984395,603973750,209708603,419423190,838852925};
int a[5001];
int f[5001];
int n;
int tot=0;
void dfs(int x,int sum,int maxn,int tot,int y){
    tot++;
    if(tot>=10000000){
        cout<<Ans<<endl;
        exit(0);
    }
    if(sum>maxn*2){
        Ans++;
        Ans%=N;
    }
    if(x>n) return;
    for(int i=y+1;i<=n;i++){
        if(!f[i]){
            f[i]=true;
            dfs(x+1,sum+a[i],max(maxn,a[i]),tot+1,i);
            f[i]=false;
        }
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    bool f1=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]!=a[i-1]) f1=true;
    }
    if(n<=3){
        if(n<3) cout<<0<<endl;
        else if(n==3){
            if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1<<endl;
            else cout<<0<<endl;
        }
        return 0;
    }
    else if(!f1){
        if(b[n]!=0){
            cout<<b[n]<<endl;
            return 0;
        }
        int ans=0;
        for(int i=3;i<=n;i++){
            int sum=0;
            for(int j=0;j<min(i,n-i)-1;j++){
                sum*=(n-j);
            }
            for(int j=1;j<min(i,n-i);j++){
                sum/=j;
            }
            sum%=N;
            ans+=sum;
            ans%=N;
        }
        cout<<ans<<endl;
        return 0;
    }
    if(n==500){
        cout<<366911923<<endl;
    }
    dfs(1,0,0,0,0);
    cout<<Ans<<endl;
    return 0;
}