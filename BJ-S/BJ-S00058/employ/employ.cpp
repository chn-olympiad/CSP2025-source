#include<bits/stdc++.h>
using namespace std;
int n,m;
int z[505];
int s[505];
int jian;
int sz;
char b;
int a[505];
int a1[505];
int ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b;
        if(b=='0'){
            sz++;
            z[sz]=z[sz-1];
            s[sz]=s[sz-1]+1;
            a1[i]=1;
        }
        if(b=='1'){
            z[sz]++;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int j=1;
    for(int i=1;i<=n;i++){
        if(a1[i]==1){
            if(a[i]<=s[j]){
                a[i]=z[j]+1;
            }
            continue;
        }
        for(;j<=sz;j++){
            if(a[j]<=s[j]){
                a1[j]=z[j]-jian;
                jian++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a1[i]!=0) ans*=a1[i];
    }
    cout<<ans;
    return 0;
}
