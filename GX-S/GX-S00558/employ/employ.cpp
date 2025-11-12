#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[100001];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=n;
    for(int i=1;i<n;i++){
        sum=(n-i)*sum;
        sum=sum%=998;
        sum=sum%244;
        sum=sum%353;
    }
    cout<<sum;
    return 0;
}
