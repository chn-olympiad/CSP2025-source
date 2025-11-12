#include <bits/stdc++.h>
using namespace std;
struct q{
    int l,r,s;
};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    long long a[n+10];
    bool f=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0 && a[i]!=1){
            f=0;
        }
    }
    int tmp=-1,l;
    vector<q> qs;
    if(f){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==k)
                cnt++;
        }
        cout<<cnt<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    
    for(int i=0;i<n;i++){
        tmp=-1;
        for(int j=i;j<n;j++){
            if(tmp==-1){
                tmp=a[j];
                l=j;
                goto j;
            }
            tmp^=a[j];
            j:if(tmp==k){
                q nq;
                // cout<<l+1<<" "<<j+1<<" "<<j-l+1<<endl;
                nq.l=l+1;
                nq.r=j+1;
                nq.s=j-l+1;
                qs.push_back(nq);
            }
        }
    }
    int dp[n+100]={0};
    for(int i=1;i<=n;i++){
        int s=0;
        for(int j=0;j<qs.size();j++){
            if(qs[j].r==i){
                s=qs[j].s;
                break;
            }
        }
        dp[i]=max(dp[i-1],dp[i-s]+1);
    }
    cout<<dp[n]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}