#include <bits/stdc++.h>
using namespace std;
bool easy[505];
pair<int,int> patient[505];
int ans=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i = 1;i<=n;i++){
        char ch;cin>>ch;
        easy[i]=ch-48;
    }
    for(int i = 1;i<=n;i++){
        cin>>patient[i].first;
        patient[i].second=i;
    }
    sort(patient+1,patient+n+1);
    do{
        int cnt=0,failure=0;
        for(int i = 1;i<=n;i++){
            if(failure>=patient[i].first){
                failure++;
            }else{
                cnt+=easy[i];
                failure+=(!easy[i]);
            }
            if(cnt>m)break;
        }
        if(cnt>=m){
            ans++;
            ans%=998244353;
        }
    }while(next_permutation(patient+1,patient+n+1));
    cout<<ans<<endl;

}
