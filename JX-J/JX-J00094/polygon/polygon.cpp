#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll qm(ll a,ll b){
    if(b == 0){
        return 1;
    }
    ll cmp = a%mod;
    ll ansq = 1;
    while(b){
        if(b%2 == 1){
            ansq = (ansq*cmp)%mod;
        }
        cmp = (cmp*cmp)%mod;
        b = b/2;
    }
    return ansq;
}
ll ans = 0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int mp[100010] = {};
    for(int i = 1;i<=n;i++){
        cin>>mp[i];
    }
    if(n<=10){
        for(int i = 1;i<(1<<n);i++){
            int sum = 0;
            int maxm = 0;
            int id = i;
            int numm = 0;
            int idi = 1;
            while(id){
                if(id%2 == 1){
                    //cout<<idi<<" ";
                    sum = sum+mp[idi];
                    numm++;
                    maxm = max(maxm,mp[idi]);
                }
                id = id/2;
                idi++;
            }
            //cout<<"\n"<<maxm<<" "<<sum<<"\n\n";
            if(numm>=3 && sum > maxm*2){
                    //cout<<"!!!!!";
                ans++;
                ans = ans%mod;
            }
        }
        cout<<ans;
        return 0;
    }
    sort(mp+1,mp+n+1);
    for(int i = 3;i<=n;i++){
        //printf("\n num<%d:\n",i);
        int l = 1;
        int r = 2;
        while(mp[l]+mp[r] <= mp[i] && r<i){
            r++;
        }
        //printf("l=%d r>=%d:",l,r);
        if(r == i){
            //printf("but r=i WA %d=%d\n",r,i);
            r = i-1;
            while(mp[l]+mp[r] <= mp[i] && l<r){
                l++;
            }
            if(l == r){
                //cout<<"this i can not make p\n";
                continue;
            }
            while(mp[l]+mp[r] > mp[i] && l<r){
                r--;
            }
            r = r+1;
            ans = (ans%mod)+(((i-r)%mod)*(qm(2,i-3)%mod))%mod;
            ans = ans%mod;
            //printf("use l%d,r>=%d,i%d to make p  ans:%d\n",l,r,i,ans);
            l = l+1;
            for(;l<i-1;l++){
                while(mp[l]+mp[r] > mp[i] && l<r){
                    r--;
                }
                r++;
                if(r<l){
                    r = l+1;
                }
                ans = (ans%mod)+(((i-r)%mod)*(qm(2,i-3)%mod))%mod-2;
                ans = ans%mod;
                //printf("use l%d,r>=%d,i%d to make p  ans:%d\n",l,r,i,ans);
            }
        }else{
            ans = (ans%mod)+(((i-r)%mod)*(qm(2,i-3)%mod))%mod;
            ans = ans%mod;
            //printf("use l%d,r>=%d,i%d to make p  ans:%d\n",l,r,i,ans);
            l++;
            for(;l<r;l++){
                while(mp[l]+mp[r] > mp[i] && l<r){
                    r--;
                }
                r++;
                if(r<l){
                    r = l+1;
                }
                ans = (ans%mod)+(((i-r)%mod)*(qm(2,i-3)%mod))%mod-2;
                ans = ans%mod;
                //printf("use l%d,r>=%d,i%d to make p  ans:%d\n",l,r,i,ans);
            }
        }
    }
    cout<<ans<<endl;
}
