#include<bits/stdc++.h>
using namespace std;
long long n,m,s[10000005],t[10000005],num,sum,numguang,j=1;
bool f;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0){
            f=0;
        }
        else{
            numguang++;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    if(m==1){
        while(s[j]==0){
            num++;
            j++;
            if(t[i]<=num){
                num++;
            }
        }
        cout<<n-num;
        return 0;
    }
    if(m==n){
        sort(t+1,t+n+1);
        for(int i=1;i<=n;i++){
            if(s[j]==0){
                cout<<0;
                return 0;
            }else{
                if(c[i]==0){
                    cout<<0;
                    return 0;
                }
            }
        }
        sum=1;
        for(int i=1;i<=n;i++){
            sum*=i;
        }
        cout<<sum;
        return 0;
    }
    if(f){
        for(int i=1;i<=n;i++){
            sum*=i;
        }
        cout<<sum;
        return 0;
    }
    cout<<0;
    return 0;
}
