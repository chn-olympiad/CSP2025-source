#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],cnt1,cnt2,cnt3,b1[N],b2[N],b3[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        cnt1=cnt2=cnt3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                cnt1++,b1[cnt1]=a[i][1]-max(a[i][2],a[i][3]);
                ans+=a[i][1];
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                cnt2++,b2[cnt2]=a[i][2]-max(a[i][1],a[i][3]);
                ans+=a[i][2];
            }
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
                cnt3++,b3[cnt3]=a[i][3]-max(a[i][2],a[i][1]);
                ans+=a[i][3];
            }
        }
        sort(b1+1,b1+cnt1+1);
        sort(b2+1,b2+cnt2+1);
        sort(b3+1,b3+cnt3+1);
        int k=1;
        while(cnt1>n/2){
            ans-=b1[k];
            k++;
            cnt1--;
        }
        while(cnt2>n/2){
            ans-=b2[k];
            k++;
            cnt2--;
        }
        while(cnt3>n/2){
            ans-=b3[k];
            k++;
            cnt3--;
        }
        cout<<ans<<endl;
    }
    return 0;
}