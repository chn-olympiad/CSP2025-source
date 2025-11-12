#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],maxlen,sum,ans;
const long long MOD=998244353;
vector<long long> v;
bool check(){
    if(v.size()<3) return false;
    else{
        if(sum>2*maxlen){
            return true;
        }else{
            return false;
        }
    }
}
set<vector<long long>> s;
void dfs(long long i){
    if(check()){
        int ll=s.size();
        s.insert(v);
    }
    if(i>n){
        return ;
    }
    int cnt1=maxlen;
    int cnt2=sum;
    maxlen=max(maxlen,a[i]);
    sum+=a[i];
    v.push_back(i);
    dfs(i+1);
    maxlen=cnt1;
    sum=cnt2;
    v.pop_back();
    dfs(i+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1LL);
    cout<<s.size()%MOD;
	return 0;
}
