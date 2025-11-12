#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const long long MOD=998244353;
long long n,m;
string s;
long long c[510];
long long cnt1[510]={0};
long long max_pos_1=0,min_pos_1=0;
vector<long long> above[510];
vector<long long> under[510];
bool used[510]={0};
long long ans=0;
bool have_above(long long above_){
    for(long long i=0;i<above[above_].size();i++){
        if(!used[i])return true;
    }
    return false;
}
void solve(long long pos,long long fail){
    long long before_cnt_0=pos-cnt1[pos]+1+fail;
    long long before_cnt_1=cnt1[pos]-1-fail;
    long long after_cnt_0=n-1-pos-(cnt1[n-1]-cnt1[pos]);
    long long after_cnt_1=cnt1[n-1]-cnt1[pos];


    if(pos==max_pos_1){
        if(before_cnt_1>=m){
            ans=(ans+1)%MOD;return;
        }
        else if(before_cnt_1==m-1&&have_above(before_cnt_0)){
            ans=(ans+1)%MOD;return;
        }
        else return;
    }
    long long next_pos_1;
    for(long long i=pos+1;i<n;i++){if(s[i]=='1'){next_pos_1=i;break;}}
    for(long long i=0;i<above[before_cnt_0].size();i++){
        if(used[above[before_cnt_0][i]]){continue;}
        used[above[before_cnt_0][i]]=1;
        solve(next_pos_1,fail);
        used[above[before_cnt_0][i]]=0;
    }
    for(long long i=0;i<under[before_cnt_0].size();i++){
        if(used[under[before_cnt_0][i]]){continue;}
        used[under[before_cnt_0][i]]=1;
        solve(next_pos_1,fail+1);
        used[under[before_cnt_0][i]]=0;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=0;i<n;i++)cin>>c[i];
    for(long long i=0;i<n;i++){
        if(i==0)cnt1[i]=s[i]-'0';
        else{
            cnt1[i]=cnt1[i-1]+s[i]-'0';
        }
        if(s[i]=='1')max_pos_1=i;
    }
    for(long long i=0;i<n;i++){
        if(s[i]=='1'){
            min_pos_1=i;break;
        }
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<c[i];j++)above[j].push_back(i);
    }
    for(long long i=0;i<n;i++){
        for(long long j=c[i];j<510;j++)under[j].push_back(i);
    }
    solve(min_pos_1,0);
    for(long long i=n-cnt1[n-1];i>=1;i--){
        ans=((ans%MOD)*(i%MOD))%MOD;
    }
    cout<<ans;
    return 0;
}
//DE BG6CNI
//A Ham From OM83.
//...
