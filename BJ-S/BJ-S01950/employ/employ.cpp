#include<bits/stdc++.h>
using namespace std;
long long a[1000],n,m,ans;
int b[1000];
string s;
int cnt=0;
void dfs(int j,int c){
    if(j==n&&c>=m){

        for(int i=1;i<=n;i++){
            cout<<b[i]<<" ";
        }
        cout<<c;
        puts("");
        ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=j;
            if(a[i]>=(j-c)||s[j]=='0'){
                dfs(j+1,c);
            }else{
                cout<<a[i]<<" "<<(j-c)<<endl;
                dfs(j+1,c+1);
            }
            b[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]!='1')cnt++;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n&&cnt==0){
        cout<<0<<endl;
        return 0;
    }
    if(1==m){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    if(n<=10){
        dfs(0,0);
        cout<<ans;
    }
    return 0;
}