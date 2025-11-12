#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5];
int c[N];
int cnt[N];
int y[N];
int ans;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    cin >> t;
    int w;
    while(t--){
        int n;
        cin >> n;
        w=n/2;
        for(int i=1;i<=n;i++){
            cin >> a[i][1]>>a[i][2]>>a[i][3];
            int k=max(a[i][1],a[i][2]);
            c[i]=max(k,a[i][3]);
            y[i]=min(k,a[i][3]);
            if(a[i][1]==c[i]){
                cnt[1]+=1;
            }else if(a[i][2]==c[i]){
                cnt[2]+=1;
            }else if(a[i][3]==c[i]){
                cnt[3]+=1;
            }
            if(cnt[1]<=w||cnt[2]<=w||cnt[3]<=w){
                ans+=c[i];
            }else if(cnt[1]>w){
                   while(cnt[1]>w){
                     cnt[1]--;
                   }
                   ans+=c[i];
            }else if(cnt[2]>w){
                   while(cnt[2]>w){
                     cnt[2]--;
                   }
                   ans+=c[i];
            }else if(cnt[3]>w){
                   while(cnt[3]>w){
                     cnt[3]--;
                   }
                   ans+=c[i];
            }

        }
         cout << ans << endl;
        ans=0;
    }

    return 0;
}
