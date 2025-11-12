#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mo=998244353;
ll n,m,s[1010100],c[1010101],a[1119191],ans,q[1010101];
string t;
ll mark[1110010];
void check(){
    int num=0;
    q[1]=s[1];
    if(s[1]==1){
        num++;
        //cout<<1<<" ";
    }
    for(int i=2;i<=n;i++){
        if(i-1-q[i-1]>=c[a[i]]){
            q[i]=q[i-1];
            continue;
        }
        q[i]=q[i-1]+s[i];
        if(s[i]==1){
            num++;
           // cout<<a[i];
        }
    }
    if(num>=m){
        ans=ans%mo+1;
    }

}
void dfs(int x){
    if(x==n+1) {
     /*  for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;*/
        check();

       return ;
    }
    for(int i=1;i<=n;i++){

        if(mark[i]==0){
         //   cout<<i<<" ";
            a[x]=i;
            //x++;
            mark[i]=1;
            dfs(x+1);
            mark[i]=0;
        }
    }
}
int main(){
   freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>t;
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    t=" "+t;
    for(int i=1;i<=n;i++){
        s[i]=t[i]-'0';
    }
    dfs(1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

//Ren5Jie4Di4Ling5%
}
