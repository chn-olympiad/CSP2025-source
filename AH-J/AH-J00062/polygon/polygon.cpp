#include<iostream>
#include<cstdio>
using namespace std;
long long MOD=998244353;
int n;
int v[5005];
int a[5005];
//对于所有 1 ≤ i ≤ n,均有 1 ≤ a i ≤ 5, 000。
//n<=5000
long long dfs(int pos,int maxn,int cnt,int sum){
    long long ps=0;
    if(pos==n+1){
        if(cnt>=3&&sum>2*maxn){
                /*for(int i=1;i<=n;i++){
                    if(v[i]){
                        cout<<i<<" ";
                    }
                }
                cout<<endl;*/
            return 1;
        }else{
            return 0;
        }
    }
    v[pos]=1;
    ps+=dfs(pos+1,max(maxn,a[pos]),cnt+1,sum+a[pos])%MOD;
    v[pos]=0;
    ps+=dfs(pos+1,maxn,cnt,sum)%MOD;
    return ps;
}
int w=0;
long long A(int x,int y){
    long long sum=1;
    for(int i=y;i>=y-x+1;i--){
        sum*=i;
        sum%=MOD;
    }
    return sum%MOD;
}
long long c(int x,int y){
    return (A(x,y)/A(x,x))%MOD;
}
long long sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            w=1;
        }
    }
    if(w==0){
        for(int i=3;i<=n;i++){
            sum+=c(i,n);
            //cout<<c(i,n)<<" ";
        }
        cout<<sum;
        return 0;
    }
    cout<<dfs(1,0,0,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//#Shang4Shan3Ruo6Shui4
