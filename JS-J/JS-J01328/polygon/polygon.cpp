#include<bits/stdc++.h>
using namespace std;
int a[5010],flag,b[5010],s[5010][5010];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    cin>>a[1]>>a[2];
    for(int i=3;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag=1;
        }
    }
    sort(a+1,a+n+1);
    if(!flag){
        ans=1;
        for(int i=2;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
    }
    if(n==3){
        cout<<(a[1]+a[2]>a[3]);
    }
    for(int i=1;i<=n;i++){
        b[i]=2*a[i];
        s[1][i]=s[1][i-1]+a[i];
        if(i<3){
            continue;
        }
        if(s[1][i]>b[i]){
            ans++;
        }
        for(int j=1;j<i;j++){
            s[j][i]=s[1][i]-s[1][j];
            if(i-j+1<3){
                continue;
            }
            if(s[j][i]>b[i]){
                ans++;
            }
            for(int k=j+1;k<i;k++){
                for(int q=k-1;q>j;q--){
                    if(s[j][i]-s[q][k]>b[i]){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<3*ans;
    return 0;
}
