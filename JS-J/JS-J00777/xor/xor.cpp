#include<bits/stdc++.h>
using namespace std;
int n,k,x;
long long ans;
short a[500005][35];
void tt(int s,int l){
    int cnt=0;
    while(s){
        a[l][++cnt]=s%2;
        s/=2;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    tt(k,0);
    for(int i=1;i<=n;i++){
        cin>>x;
        tt(x,i);
    }
    string s2="0000000000000000000000000000000000";
    for(int q=1;q<=34;q++){
        if(a[0][q]==1) s2[q]='1';
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            string s1="0000000000000000000000000000000000";
            for(int p=i;p<=j;p++){
                for(int q=1;q<=34;q++){
                    if(a[p][q]==1&&s1[q]=='0') s1[q]='1';
                    else if(a[p][q]==1&&s1[q]=='1') s1[q]='0';
                }
            }
            if(s1==s2) ans++;
        }
    }
    cout<<ans;
    return 0;
}
