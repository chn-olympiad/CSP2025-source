#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
int n;
long long ans=0;
long long length[N];
void dfs(int now_length_id,long long already_length,long long now_max,int now_num,bool flag){
    if(now_num>=3){
        if(already_length>2*now_max&&flag){
            ans++;
            ans%=MOD;
        }
    }
    if(now_length_id>n)return;
    dfs(now_length_id+1,already_length+length[now_length_id],max(now_max,length[now_length_id]),now_num+1,true);
    dfs(now_length_id+1,already_length,now_max,now_num,false);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f_one=true;
    for(int i=1;i<=n;i++){
        cin>>length[i];
        if(length[i]>1)f_one=false;
    }
    if(f_one==true){
        long long ans2=(n-1)*(n-2)/2;
        ans2%=MOD;
        cout<<ans2;
        return 0;
    }
    dfs(1,0,0,0,true);
    cout<<ans;
    return 0;
}
