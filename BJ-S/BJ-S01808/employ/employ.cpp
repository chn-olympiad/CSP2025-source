#include<iostream>
using namespace std;
long long a[100005],n,m,sum;
string s;
int p[100005];
long long g=1,k=0,cnt;
void chu(){
    for(int i=1;i<=n;i++){
        if(a[i]<=k&&p[i]==0){
            g++;
            p[i]=2;
            k++;
            chu();
        }
    }
}
void hui(){
    for(int i=1;i<=n;i++){
        if(p[i]==2&&a[i]>=k){
            p[i]=0;
            g--;
            k--;
            hui();
        }
    }
}
void dfs(long long x,long long l){
    chu();
    if(g>n){
        if(l>=m){
            cnt++;
            sum%=998244353;
        }

        return ;
    }
    for(long long i=1;i<=n;i++){
        if(p[i]==0){

                p[i]=1;
                g++;
                if(s[x-1]=='0'){
                    k++;
                    dfs(x+1,l);
                    k--;
                    hui();
                }else{
                    dfs(x+1,l+1);
                }
                p[i]=0;
                g--;
            }

        }
        return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    long long o=1,u=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            u++;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            o=0;
        }
    }
    if(o==1&&m<=n-u){
            sum=1;
        for(long long i=1;i<=n-u;i++){
            sum*=i;
            sum%=998244353;
        }
        for(long long i=1;i<=u;i++){
            sum*=i;
            sum%=998244353;
        }
        cout<<sum;
        return 0;
    }else if(o==1&&m>n-u){
        cout<<0;
    }
    if(u!=0){
    sum=1;
    for(long long i=1;i<=u;i++){
            sum*=i;
            sum%=998244353;
        }
    }
    dfs(1,0);
    cout<<sum*cnt%998244353;
    return 0;
}
