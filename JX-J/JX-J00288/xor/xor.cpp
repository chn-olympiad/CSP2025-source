#include<bits/stdc++.h>
using namespace std;
long long top;
long long n,k;
bool vis[500010];
long long a[500010];
pair<int,int> p[500010];
long long ans;
bool cmp(pair<int,int> x,pair<int,int> y){
    int asdf1=x.second-x.first;
    int asdf2=y.second-y.second;
    if(asdf1==asdf2){
        int sum1=0;
        int sum2=0;
        for(int i=1;i<=top;i++){
            if((x.first>=p[i].first&&x.first<=p[i].second)||(x.second>=p[i].first&&x.second<=p[i].second)){
                sum1++;
            }
            if((y.first>=p[i].first&&y.first<=p[i].second)||(y.second>=p[i].first&&y.second<=p[i].second)){
                sum2++;
            }
        }
        return sum1<sum2;
    }
    return asdf1<asdf2;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int sum=a[i];
        if(sum==k){
            if(sum==k){
                p[++top]={i,i};
                //cout<<i<<" "<<i<<endl;
            }
        }
        for(int j=i+1;j<=n;j++){
            sum^=a[j];
            if(sum==k){
                p[++top]={i,j};
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    sort(p+1,p+1+top,cmp);
    for(int i=1;i<=top;i++){
        bool flag=1;
        for(int j=p[i].first;j<=p[i].second;j++){
            if(vis[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            ans++;
            for(int j=p[i].first;j<=p[i].second;j++){
                vis[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
