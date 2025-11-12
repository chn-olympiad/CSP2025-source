#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
ll a[(int)1e6+10][5];
ll A[(int)1e6+10];
ll si[5];
ll ans;
ll s[(int)1e6+10];
bool cmp(ll x,ll y){
    return x>y;
}
void dfs(ll k,ll cnt){
    if(k==n+1){
        ans=max(ans,cnt);
    }
    if(cnt+s[n]-s[k-1]<=ans)return;
    if(si[1]<n/2){
            si[1]++;
        dfs(k+1,a[k][1]+cnt);
    si[1]--;
    }if(si[2]<n/2){
            si[2]++;
        dfs(k+1,a[k][2]+cnt);
    si[2]--;
    }if(si[3]<n/2){
            si[3]++;
        dfs(k+1,a[k][3]+cnt);
    si[3]--;
    }
}
int main(){
   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
            si[1]=si[2]=si[3]=0;
            ans=0;
        cin>>n;
        bool isA=1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0){
                isA=0;
            }
            A[i]=a[i][1];
            s[i]=s[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
        }
        if(isA){
            sort(A+1,A+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=A[i];
            }
            cout<<ans<<endl;
            continue;
        }else{
            dfs(1,0);
        }
        cout<<ans<<endl;
    }

    return 0;
}
