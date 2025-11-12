#include<iostream>
#include<algorithm>
using namespace std;
const int N=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n;
    int q;
    cin>>q;
    int cnt=0;
    string s;
    cin>>s;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(a[cnt+1]==0){
        cnt++;
    }
    if(n-cnt<q){
        cout<<0;
        return 0;
    }
    int ans=1,ans1=1;
    for(int i=cnt;i<n;i++){
        ans*=n-i;
        ans%=N;
    }
    while(a[cnt+1]==1){
        cnt++;
    }
    for(int i=cnt;i<n;i++){
        ans1*=n-i;
        ans1%=N;
    }
    cout<<ans+ans1;
    return 0;
}
