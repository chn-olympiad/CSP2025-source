#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
const ll mod = 998244353;
ll n,a[N],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n == 3){
        int a,b,c;
        cin>>a>>b>>c;
        int nmax = max(max(a,b),max(b,c));
        if(nmax == a){
            if(b + c > a){
                cout<<1;
                return 0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        else if(nmax == b){
            if(a + c > b){
                cout<<1;
                return 0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        else{
            if(a + b > c){
                cout<<1;
                return 0;
            }
            else{
                cout<<0;
                return 0;
            }
        }
    }
    ll nmax = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        nmax = max(nmax,a[i]);
    }
    sort(a + 1,a + n + 1);
    if(nmax == 1){
        ll tmp = 0;
        for(int i = 1;i <= n - 2;i++){
            tmp += i;
        }
        cout<<tmp % mod;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                if(a[i] + a[j] > a[k])ans++;
            }
        }
    }
    ans %= mod;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                for(int m = k + 1;m <= n;m++){
                    if(a[i] + a[j] + a[k] > a[m])ans++;
                }
            }
        }
    }
    ans %= mod;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                for(int m = k + 1;m <= n;m++){
                    for(int ii = m + 1;ii <= n;ii++){
                        if(a[i] + a[j] + a[k] + a[m] > a[ii])ans++;
                    }
                }
            }
        }
    }
    ans %= mod;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                for(int m = k + 1;m <= n;m++){
                    for(int ii = m + 1;ii <= n;ii++){
                        for(int jj = ii + 1;jj <= n;jj++){
                            if(a[i] + a[j] + a[k] + a[m] + a[ii] > a[jj])ans++;
                        }
                    }
                }
            }
        }
    }
    ans %= mod;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                for(int m = k + 1;m <= n;m++){
                    for(int ii = m + 1;ii <= n;ii++){
                        for(int jj = ii + 1;jj <= n;jj++){
                            for(int zz = jj + 1;zz <= n;zz++){
                                if(a[i] + a[j] + a[k] + a[m] + a[ii] + a[jj] > a[zz])ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    ans %= mod;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                for(int m = k + 1;m <= n;m++){
                    for(int ii = m + 1;ii <= n;ii++){
                        for(int jj = ii + 1;jj <= n;jj++){
                            for(int zz = jj + 1;zz <= n;zz++){
                                for(int mm = zz + 1;mm <= n;mm++){
                                    if(a[i] + a[j] + a[k] + a[m] + a[ii] + a[jj] + a[zz] > a[mm])ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ans %= mod;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                for(int m = k + 1;m <= n;m++){
                    for(int ii = m + 1;ii <= n;ii++){
                        for(int jj = ii + 1;jj <= n;jj++){
                            for(int zz = jj + 1;zz <= n;zz++){
                                for(int mm = zz + 1;mm <= n;mm++){
                                    for(int ij = mm + 1;ij <= n;ij++){
                                        if(a[i] + a[j] + a[k] + a[m] + a[ii] + a[jj] + a[zz] + a[mm] > a[ij])ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ans %= mod;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                for(int m = k + 1;m <= n;m++){
                    for(int ii = m + 1;ii <= n;ii++){
                        for(int jj = ii + 1;jj <= n;jj++){
                            for(int zz = jj + 1;zz <= n;zz++){
                                for(int mm = zz + 1;mm <= n;mm++){
                                    for(int ij = mm + 1;ij <= n;ij++){
                                        for(int kk = ij + 1;kk <= n;kk++){
                                            if(a[i] + a[j] + a[k] + a[m] + a[ii] + a[jj] + a[zz] + a[mm] + a[ij] > a[kk])ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans % mod;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
