#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[100005][3],cnt[3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int sum=0;
        cnt[0]=cnt[1]=cnt[2]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int t=max_element(a[i]+0,a[i]+3)-a[i];
            cnt[t]++;
            sum+=a[i][t];
        }
        if(max({cnt[0],cnt[1],cnt[2]})<=n/2){
            cout<<sum<<"\n";
        }else{
            vector<int>vec;
            for(int i=1;i<=n;i++){
                int t=max_element(a[i]+0,a[i]+3)-a[i];
                if(cnt[t]>n/2){
                    stable_sort(a[i]+0,a[i]+3);
                    vec.push_back(a[i][2]-a[i][1]);
                }
            }
            stable_sort(vec.begin(),vec.end());
            int k=max({cnt[0],cnt[1],cnt[2]})-n/2;
            for(int i=0;i<k;i++){
                sum-=vec[i];
            }
            cout<<sum<<"\n";
        }
    }
    return 0;
}