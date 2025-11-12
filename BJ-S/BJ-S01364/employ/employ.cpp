#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0,p=998244353;
string s;
long long a[1005],b[1005],vis[1005];
void dfs(int x){
    if(x>n){
        int cnt=0,t1=0;
        for(int i=1;i<=n && t1<=n;i++){
            t1++;
            while(b[t1]<=0 && t1<=n){
                t1++;
                for(int j=t1;j<=n;j++){
                    b[j]--;
                }
            }
            if(s[i]=='0'){
                for(int j=t1+1;j<=n;j++){
                    b[j]--;
                }
            }else{
                cnt++;
            }
        }
        if(cnt>=m){
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            b[x]=a[i];
            dfs(x+1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int flag=0;
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(s[i]=='0'){
            flag=1;
        }
    }
    if(flag==1){
        dfs(1);
        cout<<ans<<endl;
    }else{
        long long sum=1;
        for(int i=1;i<=n;i++){
            sum=(sum*i)%p;
        }
        cout<<sum<<endl;
    }
    return 0;
}