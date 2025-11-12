#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005],slct[100005],sec[100005],mi[100005],cnt1,cnt2,cnt3,cnt,ans,ex;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cnt1=0;
        cnt2=0;
        cnt3=0;
        cnt=0;
        ans=0;
        ex=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a1[i]>=a2[i] && a1[i]>=a3[i]){
                slct[i]=1;
                sec[i]=max(a2[i],a3[i]);
                cnt1++;
            }
            else if(a2[i]>=a1[i] && a2[i]>=a3[i]){
                slct[i]=2;
                sec[i]=max(a1[i],a3[i]);
                cnt2++;
            }
            else{
                slct[i]=3;
                sec[i]=max(a1[i],a2[i]);
                cnt3++;
            }
        }
        for(int i=1;i<=n;i++){
            if(slct[i]==1)ans+=a1[i];
            else if(slct[i]==2)ans+=a2[i];
            else ans+=a3[i];
        }
        if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2){
            cout<<ans<<endl;
        }
        else{
            if(cnt1>n/2){
                for(int i=1;i<=n;i++){
                    if(slct[i]==1){
                        mi[++cnt]=a1[i]-sec[i];
                    }
                }
            }
            else if(cnt2>n/2){
                for(int i=1;i<=n;i++){
                    if(slct[i]==2){
                        mi[++cnt]=a2[i]-sec[i];
                    }
                }
            }
            else if(cnt3>n/2){
                for(int i=1;i<=n;i++){
                    if(slct[i]==3){
                        mi[++cnt]=a3[i]-sec[i];
                    }
                }
            }
            sort(mi+1,mi+cnt+1);
            ex=cnt-n/2;
            for(int i=1;i<=ex;i++)ans-=mi[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}
