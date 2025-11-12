#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans,num;
bool fl;
string s;
const int MAXDB=998244353;
bool checkA(string s){
    for(int i=0;i<n;i++){
        if(s[i]!=1){
            return false;
        }
    }
    return true;
}
void dp(string s,int cnt,int i){
    if(num>=m){
        ans++;
    }
    if(s[i]=='1'){
        if(cnt<c[i]){
            num++;
        }else{
            cnt++;
        }
    }else{
        cnt++;
    }
    dp(s,cnt,i+1);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(checkA){
        ans=1;
        for(int i=1;i<=500;i++){
            ans*=i;
        }
        cout<<ans;
    }else{
        if(m==n){
            for(int i=0;i<s.size();i++){
                if(s[i]=='0'){
                    cout<<0;
                    fl=true;
                }
            }
            if(fl=false){
                ans=1;
                for(int i=1;i<=n;i++){
                    ans*=i;
                    ans%=MAXDB;
                }
                cout<<ans;
            }
        }else{
            if(m==1){
                for(int i=0;i<s.size();i++){
                    if(s[i]=='1'){
                        ans=1;
                        for(int i=1;i<=n;i++){
                            ans*=i;
                            ans%=MAXDB;
                        }
                        cout<<ans;
                        fl=true;
                    }
                }
                if(fl==false){
                    cout<<0;
                }
            }else{
                dp(s,0,1);
                cout<<ans;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
