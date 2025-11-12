#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,cnt[4];
ll a[100001][4];
vector<ll> vec[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>t;
    while(t--){
        cin >>n;
        ll ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=3;i++) vec[i].clear();
        for(int i=1;i<=n;i++){
            ll maxn=-1,maxid=0,cmaxn=-1,cmaxid=0;
            for(int j=1;j<=3;j++){
                cin >>a[i][j];
                if(a[i][j]>maxn){
                    cmaxn=maxn;cmaxid=maxid;
                    maxn=a[i][j];maxid=j;
                }else if(a[i][j]>cmaxn){
                    cmaxn=a[i][j];
                    cmaxid=j;
                }
            }
            cnt[maxid]++;
            vec[maxid].push_back(maxn-cmaxn);
            //cout <<maxn <<" ";
            ans+=maxn;
        }
        //cout <<ans <<" ";
        ll flag=0;
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2) flag=i;
        }
        sort(vec[flag].begin(),vec[flag].end());
        for(int i=0;i<cnt[flag]-(n/2);i++){
            ans-=vec[flag][i];
        }
        cout <<ans <<'\n';
    }

    return 0;
}
