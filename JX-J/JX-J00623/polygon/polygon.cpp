#include<bits/stdc++.h>
using namespace std;
int a[100];
int ans=0,n;
map<int,string> k;
int o=0;
void dfs(int st,string s){
    if(st>n){
        k[++o]=s;
        return;
    }
    dfs(st+1,s+"0");
    dfs(st+1,s+"1");
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    dfs(1,"");
    for(int i=1;i<=o;i++){
        string str=k[i];
        int cnt=0,sum=0,ma=0;
        for(int j=0;j<n;j++){
            if(str[j]=='1'){
                sum++;
                cnt+=a[j+1];
                ma=max(ma,a[j+1]);
            }
        }if(sum>=3&&cnt>ma*2)ans++;
    }
    cout << ans;
    return 0;
}
