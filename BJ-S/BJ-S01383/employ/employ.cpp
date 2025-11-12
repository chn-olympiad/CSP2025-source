#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000005],sum;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    if(n<=10){
    for(int i=1;i<=n;i++){
        cin>>c[i];
        c[i]=c[i]+10000000*i;
    }
    sort(c+1,c+n+1);

    do{
        int mm=m;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'&&ans<c[i]%1000000){
                mm--;
            }
            else{
                ans++;
            }
        }
        if(mm<=0){
            sum++;
        }
    }while(next_permutation(c+1,c+n+1));
    cout<<sum%998224353;
    return 0;
    }
    bool b=1;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1'){
            b=0;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];

    }
    if(m==n&&!b){
        cout<<0;
        return 0;
    }
    else if(m==n&&b){
           int ans=0,sum=1;
        for(int i=1;i<=n;i++){
            if(c[i]==0){
                ans++;
            }
        }
        if(ans>0){cout<<0;return 0;}
        for(int i=1;i<=n;i++){
                sum=(sum*i)%998224353;
            }
            cout<<sum%998224353;
    }
    else if(b){
            int ans=0,sum=1;
        for(int i=1;i<=n;i++){
            if(c[i]==0){
                ans++;
            }
        }

        if(m+ans<=n){
            for(int i=1;i<=n;i++){
                sum=(sum*i)%998224353;
            }
            cout<<sum%998224353;
        }
        else cout<<0;
    }

}
