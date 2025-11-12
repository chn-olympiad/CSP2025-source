#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,z,xx;
string s;
int a[1000005],b[1000005];
int dfs(int jin,int gun){
    int num=0;
    if(jin+gun==x){
        if(jin>=y){
            return 1;
        }
    }else{
        for(int i=1;i<=x;i++){
            if(b[i]==0){
                b[i]=1;
                if(a[i]>gun&&s[jin+gun]=='1'){
                    num+=dfs(jin+1,gun);
                }else{
                    num+=dfs(jin,gun+1);
                }
                b[i]=0;
            }
        }
    }
    return num%998244353;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>x>>y;
    cin>>s;
    xx=x;
    for(int i=1;i<=x;i++){
        cin>>a[i];
        if(a[i]==0){
            xx--;
        }
    }
    if(xx<y){
        cout<<0;
        return 0;
    }
    bool q=1;
    for(int i=0;i<s.size();i++){
        q&=s[i]-'0';
    }
    if(!q||xx!=s.size()){
        cout<<dfs(0,0);
    }else{
        int sum=1;
        for(int i=2;i<=xx;i++){
            sum*=i;
            sum%=998244353;
        }
        cout<<sum;
    }
    return 0;
}
