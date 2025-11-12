#include<bits/stdc++.h>
using namespace std;

int c[100005],dx[100005];
int n,m;
string s;
int f1(){
    int ju,cnt=0;
    do{
        ju=0;
        for(int i=0;i<n;i++)
           if(c[dx[i]]<=ju || s[i]=='0')
                ju++;
        if(ju<=n-m) cnt++;
    }while(next_permutation(dx,dx+n));
    return cnt%998244353;
}
int f2(){
    for(int i=0;i<n;i++)
        if(s[i]=='0' || c[i]==0)
            return 0;
    int ans=1;
    for(int i=n;i>=2;i--)
        ans=(ans*i)%998244353;
    return ans;
}


int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
        dx[i]=i;
    }
    if(m==n)
        cout<<f2();
    else
        cout<<f1();
    return 0;
}
