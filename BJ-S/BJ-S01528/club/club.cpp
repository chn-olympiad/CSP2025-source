#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[500005][10];
int maxm1[500005],maxm2[500005],maxm3[500005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long sum=0;
        cin>>n;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            int maxx=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                maxx=max(maxx,a[i][j]);
            }
            sum+=maxx;
            if(maxx==a[i][1]){
                cnt1++;
                maxm1[cnt1]=a[i][1]-max(a[i][2],a[i][3]);
            }
            else if(maxx==a[i][2]){
                cnt2++;
                maxm2[cnt2]=a[i][2]-max(a[i][1],a[i][3]);
            }
            else if(maxx==a[i][3]){
                cnt3++;
                maxm3[cnt3]=a[i][3]-max(a[i][2],a[i][1]);
            }
        }
        if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
            cout<<sum<<endl;
        }
        else{
            if(cnt1>n/2){
                sort(maxm1+1,maxm1+cnt1+1);
                for(int i=1;i<=cnt1-n/2;i++){
                    sum-=maxm1[i];
                }
            }
            else if(cnt2>n/2){
                sort(maxm2+1,maxm2+cnt2+1);
                for(int i=1;i<=cnt2-n/2;i++){
                    sum-=maxm2[i];
                }
            }
            else if(cnt3>n/2){
                sort(maxm3+1,maxm3+cnt3+1);
                for(int i=1;i<=cnt3-n/2;i++){
                    sum-=maxm3[i];
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
