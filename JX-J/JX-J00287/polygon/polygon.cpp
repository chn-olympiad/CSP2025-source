#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

long long a[5005],sum[5005];
long long n;

long long ans = 0;
unordered_map<string,bool>ump(3000000);
void dfs(long long x,long long cnt,long long sum,long long maxs,string s){
    if(x > n){
        if(cnt >= 3 && sum > maxs*2 && ump.count(s) == 0){
            ans++;
            ump[s] = 1;
        //    cout<<s<<" ";
        //    cout<<"right--";
        }
    //    cout<<sum<<" "<<maxs<<endl;
        return;
    }
    dfs(x+1,cnt+1,sum+a[x],a[x],s+"1");
    dfs(x+1,cnt,sum,maxs,s+"0");

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    string st = "";
    dfs(1,0,0,0,st);
    cout<<ans;

    return 0;
}
