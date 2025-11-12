#include<bits/stdc++.h>
using namespace std;
long long an[500010][2],n,k,arr[500010],inde=0,dp[500010],l=1e18,r=0,ans;
int vis;
typedef pair<int,int> pii;
vector<pii> v[50010],vv;

long long coun(int l,int r){
    if(l==r)return arr[l];
    long long ans=arr[l];
    for(int i=l+1;i<=r;i++){
        ans=(ans xor arr[i]);
    }
    return ans;
}

long long fun(int ind,int ll,int rr){
    ans=0;
    vis=v[ind].size();
    for(int i=0;i<vis;i++){

        if(v[ind][i].first<=rr and ll<=v[ind][i].second)ans++;
        else vv.push_back({v[ind][i].first,v[ind][i].second});
    }
    while(v[ind].size())v[ind].pop_back();
    while(!vv.empty()){
        v[ind].push_back(vv.back());
        vv.pop_back();
    }
    return ans;
}


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)dp[i]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        l=min(l,arr[i]);
        r=max(r,arr[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            long long sum=coun(i,j);
            //printf("%d %d sum:%d\n",i,j,sum);
            if(sum==k){
                an[++inde][0]=i;
                an[inde][1]=j;
            }
        }
    }
    for(int i=1;i<=inde;i++){
        for(int j=r;j>=l;j--){
            long long jian=fun(j,an[i][0],an[i][1]);
            dp[j]=max(dp[j],dp[j]-jian+1);
            v[j].push_back({an[i][0],an[i][1]});
        }
    }


    cout<<dp[r];
    return 0;
}

