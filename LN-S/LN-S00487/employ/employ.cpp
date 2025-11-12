#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],n0,flag=1;
long long ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]==0){
            flag=0;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    /*for(int i=1;i<=n;i++){
        if(c[i]<=0){
            for(int j=i+1;j<=n;j++){
                c[j]--;
            }
        }
    }*/
    for(int i=1;i<=n;i++){
        if(c[i]>0){
            break;
        }else{
            n0++;
        }
    }
    cout<<endl;
    if(flag){
            int q,h;
        /*n-=n0;
        ans=1;
        for(int i=m;i<=n;i++){
            ans=ans*i;
        }
        cout<<n0<<" "<<ans%998244353;*/
        ans=1;
        for(int i=n0+1;i<=n;i++){
            if(c[i]>n0){
                q=i-n0-1;
                h=n-i+1;
                break;
            }
        }
        for(int i=q;i>=1;i--){
            ans*=i;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
