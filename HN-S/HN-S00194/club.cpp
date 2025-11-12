#include<bits/stdc++.h>
using namespace std;
const int kmaxn=1e5+10;
int T,n,a[kmaxn][3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        vector<int>A[3];
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int d=max(max(a[i][0],a[i][1]),a[i][2]);
            ans=ans+d;
//            cout<<d<<" "<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<"!!!\n";
            for(int j=0;j<3;j++){
                if(d==a[i][j]){
                    A[j].push_back(i);break;
                }
            }
        }
//        cout<<A[0].size()<<" "<<A[1].size()<<" "<<A[2].size()<<" "<<n<<"!\n";
        if(max({A[0].size(),A[1].size(),A[2].size()})<=n/2){
            cout<<ans<<"\n";continue;
        }
        if(A[0].size()>n/2){
            vector<int>t;
            for(int i:A[0]){
                t.push_back(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
            }
            sort(t.begin(),t.end());
            for(int j=0;t.size()-j>n/2;j++)ans-=t[j];
            cout<<ans<<"\n";
        }
        if(A[1].size()>n/2){
            vector<int>t;
            for(int i:A[1]){
                t.push_back(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
            }
            sort(t.begin(),t.end());
            for(int j=0;t.size()-j>n/2;j++)ans-=t[j];
            cout<<ans<<"\n";
        }
        if(A[2].size()>n/2){
            vector<int>t;
            for(int i:A[2]){
                t.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][0]));
            }
            sort(t.begin(),t.end());
            for(int j=0;t.size()-j>n/2;j++)ans-=t[j];
            cout<<ans<<"\n";
        }
    }
    return 0;
}