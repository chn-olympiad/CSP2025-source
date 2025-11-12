//20pts
/*#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N];
int main(){
    int n,k,now=0,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if((now^a[i])==k){
            now^=a[i];
            cnt++;
            now=0;
        }else{
            now^=a[i];
        }
    }
    cout<<cnt;
    return 0;
}*/
//TLE+MLE about 30-50pts
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[200005][2005];
int n,k,mmax;
int dfs(int pos,int cnt){
    if(b[pos][cnt]){
        return b[pos][cnt];
    }
    int now=a[pos];
    if(now==k){
        for(int i=pos+1;i<=n;i++){
            dfs(i,cnt+1);
        }
    }
    for(int i=pos+1;i<=n;i++){
        now^=a[i];
        if(now==k){
            if(i==n){
                cnt++;
            }
            for(int j=i+1;j<=n;j++){
                dfs(j,cnt+1);
            }
        }
    }
    mmax=max(mmax,cnt);
    b[pos][cnt]=mmax;
    return mmax;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int allmax=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        allmax=max(allmax,dfs(i,0));
    }
    cout<<allmax;
    return 0;
}
