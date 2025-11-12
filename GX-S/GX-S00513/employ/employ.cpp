#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int ac[2];
int pt[505];
unsigned long long ans;
void dfs(int k,int no,int yes){
    cout<<k<<" "<<no<<" "<<yes<<endl;
    if(k>n){
        if(yes>=m){
            cout<<"det"<<endl;
            ans++;
            ans%=998244353;
        }
        return;
    }
    else{
        if(pt[k]>no&&yes<ac[1]){
            dfs(k+1,no,yes+1);
        }
        dfs(k+1,no+1,yes);
        return;
    }
}
int main(){
    freopen("employ3.in","r",stdin);
    //freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            ac[0]++;
        }
        else{
            ac[1]++;
        }
    }
    //cout<<ac[0]<<endl;
    for(int i=1;i<=n;i++){
        cin>>pt[i];
    }
    dfs(1,0,0);
    //ans=1;
    //for(unsigned long long i=2;i<=n;i++){
    //    ans*=i;
    //    ans%=998244353;
    //}
    cout<<ans;
    return 0;
}
