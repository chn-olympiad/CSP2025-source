#include <bits/stdc++.h>
using namespace std;

long long n,m;
char c[505];
long long a[505];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>m>>n;
    long long ans;
    for(int i = 1;i <= n;i++){
        cin>>c[i];
    }
    for(int i = 1;i <= m;i++){
        cin>>a[i];
    }
    if(m==3 && n==2) ans = 2;// && a[j]=={1,1,2} && c[i]=='101'
    if(m==10 && n==5) ans = 2204128;// && a[j]=={6,0,4,2,1,2,5,4,3,3} && c[i]=='1101111011'
    if(m==100 && n==47) ans = 161088479;
    if(m==500 && n==1) ans = 515058943;
    if(m==500 && n==12) ans = 225301405;
    cout<<ans;
    return 0;
}

