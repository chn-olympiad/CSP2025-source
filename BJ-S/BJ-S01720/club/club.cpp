#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][5],s[100005],cnt[5],ans;
int myd(){
    int ret = 0;
    for(int i=1;i<=n;i++){
        ret += a[i][s[i]];
    }
    return ret;
}
void club(){
    memset(a,0,sizeof(a));
    cin>>n;
    int m = n/2,c=0;
    cnt[1] = m+1,cnt[2] = m-1,cnt[3] = 0,ans = -1e5;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        if(i<=m)s[i] = 1;
        else s[i] = 2;
    }
    s[n] = 1;
    long long p = pow(3,n);
    for(int i=1;i<=p;i++){
        cnt[s[n]]--;
        s[n]++;
        cnt[s[n]]++;
        for(int k=n;k>=2;k--){
            if(s[k] > 3){
                cnt[s[k]]--;
                cnt[s[k-1]]--;
                cnt[++s[k-1]]++;
                //s[k-1]++;
                s[k] = 1;
                cnt[s[k]]++;
            }
        }
        if(cnt[1]>m||cnt[2]>m||cnt[3]>m){
            //cout<<++c<<endl;
            continue;
        }
        int ne = myd();
        //cout<<ne<<endl;
        ans = max(ans,ne);
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        club();
    }
    return 0;
}
