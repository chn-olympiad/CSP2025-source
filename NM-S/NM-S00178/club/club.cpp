#include<bits/stdc++.h>
using namespace std;
long long t,n,h,i,l;
long long j[3],ans[1000000];
pair<long long,long long>a[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    l=t;
    while(t--){
        cin>>n;
        h=n/2;
        long long d1[50001],d2[50001],j[3];
        for(int p=1;p<=n;p++){
            for(int q=1;q<=3;q++){
                cin>>i;
                a[q]={i,q};
            }
            sort(a+1,a+3+1);
            d1[p]=a[2].first-a[1].first;
            d2[p]=a[3].first-a[2].first;
            ans[t]=ans[t]+a[3].first;
            j[a[3].second]++;
            if(j[a[3].second]>h){
                if(d2[p]>d2[p-1]){
                    ans[t]=ans[t]-d2[p-1];
                    j[a[3].second]--;
                    j[a[2].second]++;
                }
                else{
                    ans[t]=ans[t]-d2[p];
                    j[a[3].second]--;
                    j[a[2].second]++;
                }
            }
            if(j[a[2].second]>h){
                if(d1[p]>d1[p-1]){
                    ans[t]=ans[t]-d1[p-1];
                    j[a[2].second]--;
                    j[a[1].second]++;
                }
                else{
                    ans[t]=ans[t]-d1[p];
                    j[a[2].second]--;
                    j[a[1].second]++;
                }
            }
        }
    }
    for(int o=l-1;o>=0;o--){
        cout<<ans[o]<<endl;
    }
    return 0;
}
