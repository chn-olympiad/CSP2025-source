#include<bits/stdc++.h>
using namespace std;
long long a1[100200];
long long n,a,b,c,t;
void q(){
    cin>>n;
    long long ans = 0;
    for(int i = 0;i<n;i++){
        cin>>a>>b>>c;
        a1[i] = a;
    }
    int n1 = 0;
    sort(a1,a1+n);
    for(int i = n-1;i>=0;i--){
        if(n1 + 1 <= n/2)ans += a1[i];
        else break;
        n1++;
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i = 0;i<t;i++){
        q();
    }
}
