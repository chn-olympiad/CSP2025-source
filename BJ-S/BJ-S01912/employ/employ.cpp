#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,b[114514];
const long long mod=998244353;
string a1;
int a[114514];
char a2[114514];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    int q=1,ls9;
    for(int i=1;i<=n;i++){
        b[i]=a1[i-1]-'0';
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        a2[i]=a[i]+'0';
    }
    do{
        int wlq=0,lq=0;
        for(int i=1;i<=n;i++){
            if(b[i]==0||wlq>=a2[i]-'0'){
                wlq++;
                continue;
            }
            else{
                lq++;
            }
        }
        if(lq>=m){
            ans++;
            ans%=998244353;
        }
    }while(next_permutation(a2+1,a2+n+1));
    cout<<ans<<endl;
    return 0;
}