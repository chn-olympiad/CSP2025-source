#include<bits/stdc++.h>
using namespace std;
int m,n;
char s[1000];
int a[1000];
int c[1000];
long long ans=1;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        a[i]=s[i]-'0';
    }
    int b=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]==0) b++;
    }
    if(n-b<m) {
        cout<<0;
        return 0;
    }
    sort(c,c+n,cmp);
    for(int i=0;i<n;i++){
        if(c[i]==0) break;
        ans*=(i+1);
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
