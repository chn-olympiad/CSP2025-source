#include<iostream>
#include<algorithm>
using namespace std;
int a;
int c1,c2,c3;
int f[505][505][505];
int t,a1[100005],a2[100005],a3[100005];
int n,w1,w2,w3;
long long dfs(int pos,int sum){
    if(pos==n+1){
        return sum;
    }
    long long maxn=0;
    if(c1>0&&w1==1){
        c1--;
        maxn=max(maxn,dfs(pos+1,sum+a1[pos]));
        c1++;
    }
    if(c2>0&&w2==1){
        c2--;
        maxn=max(maxn,dfs(pos+1,sum+a2[pos]));
        c2++;
    }
    if(c3>0&&w3==1){
        c3--;
        maxn=max(maxn,dfs(pos+1,sum+a3[pos]));
        c3++;
    }
    return maxn;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        w1=0,w2=0,w3=0;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a2[i]!=0){
                w2=1;
            }
            if(a3[i]!=0){
                w3=1;
            }
            if(a1[i]!=0){
                w1=1;
            }
        }
        if(w2==0&&w3==0){
            int sum=0;
            for(int i=1;i<=n;i++){
                sum+=a1[i];
            }
            cout<<sum<<endl;
            continue;
        }
        if(n<=1000){
            for(int i=1;i<=n;i++){
                for(int k1=n/2;k1>=0;k1--){
                    for(int k2=n/2;k2>=0;k2--){
                        for(int k3=n/2;k3>=0;k3--){
                            f[k1][k2][k3]=0;
                            if(k1){
                                f[k1][k2][k3]=max(f[k1][k2][k3],f[k1-1][k2][k3]+a1[i]);
                            }
                            if(k2){
                                f[k1][k2][k3]=max(f[k1][k2][k3],f[k1][k2-1][k3]+a2[i]);
                            }
                            if(k3){
                                f[k1][k2][k3]=max(f[k1][k2][k3],f[k1][k2][k3-1]+a3[i]);
                            }
                            //cout<<i<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<f[k1][k2][k3]<<" "<<f[k1][k2][k3-1]<<endl;
                        }
                    }
                }
            }
            int maxn=0;
            for(int k1=0;k1<=n/2;k1++){
                for(int k2=0;k2<=n/2;k2++){
                    for(int k3=0;k3<=n/2;k3++){
                        if(k1+k2+k3==n){
                            maxn=max(maxn,f[k1][k2][k3]);
                        }
                    }
                }
            }
            cout<<maxn<<endl;
            continue;
        }
        c1=n/2;
        c2=n/2;
        c3=n/2;
        cout<<dfs(1,0)<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
