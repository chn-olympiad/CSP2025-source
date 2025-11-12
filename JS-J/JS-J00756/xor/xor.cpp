#include<bits/stdc++.h>
using namespace std;
const int N =5e5+5;
int a[N];
string to_two(int x){
    string st;
    if(x==0){
        st='0';
    }
    while(x){
        st+=(x%2+'0');
        x/=2;
    }
    return st;
}
int xor1(int x,int y){
    string tx=to_two(x),ty=to_two(y);
    int sum=0;
    for(int i=0;i<min(tx.length(),ty.length());i++){
        if(tx[i]!=ty[i]){
            sum+=pow(2,i);
        }
    }
    for(int i=min(tx.length(),ty.length());i<max(tx.length(),ty.length());i++){
        sum+=pow(2,i);
    }
    return sum;
}
int t;
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        t=0;
        for(int j=i;j<=n;j++){
            t=xor1(t,a[j]);
            if(t==k){
                i=j;
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
