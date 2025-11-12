#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010];
bool check1(){
    for(int i=1;i<=n;i++) if(a[i]!=1) return false;
    if(k==0) return true;
    return false;
}
bool check2(){
    for(int i=1;i<=n;i++) if(a[i]>1) return false;
    if(k<=1) return true;
    return false;
}
int s1(){
    int cnt=0;
    for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
    return cnt;
}
int s2(){
    int cnt=0;
    for(int i=1;i<=n;i++) if(a[i]==0||a[i]==a[i-1]&&a[i]==1){cnt++;a[i]=0;}
    return cnt;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(check1()) cout<<n/2;
    else if(check2()){
        if(k==1) cout<<s1();
        else if(k==0) cout<<s2();
    }
    return 0;
}

