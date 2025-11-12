#include<bits/stdc++.h>
using namespace std;
int n;
const int N=100010;
int a[N][4];
int t;
long long ans=0;
int f[4];
int a1[N],a2[N],a3[N];
int cnt1=0,cnt2=0,cnt3=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        cnt1=0;
        cnt2=0;
        cnt3=0;
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;i++){
            if(a[i][1]>=max(a[i][2],a[i][3])){
                ans+=a[i][1];
                a1[cnt1++]=a[i][1]-max(a[i][2],a[i][3]);
            }
            else if(a[i][2]>=max(a[i][1],a[i][3])){
                ans+=a[i][2];
                a2[cnt2++]=a[i][2]-max(a[i][1],a[i][3]);
                //cout<<cnt2<<"%";
            }
            else if(a[i][3]>=max(a[i][1],a[i][2])){
                ans+=a[i][3];
                a3[cnt3++]=a[i][3]-max(a[i][1],a[i][2]);
            }
        }
        int k=n/2;
        if(cnt1<=k&&cnt2<=k&&cnt3<=k){
            //cout<<cnt2<<"&";
            cout<<ans<<endl;
            continue;
        }
        else if(cnt1>=k){
            sort(a1,a1+cnt1);
            for(int i=0;i<=cnt1-k-1;i++) ans-=a1[i];
        }
        else if(cnt2>=k){
            sort(a2,a2+cnt2);
            //cout<<cnt2<<"!";
            //cout<<a2[1]<<" ";
            for(int i=0;i<=cnt2-k-1;i++) ans-=a2[i];
        }
        else if(cnt3>=k){
            sort(a3,a3+cnt3);
            for(int i=0;i<=cnt3-k-1;i++) ans-=a3[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
