#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    int cnt=0;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<=cnt){
            n--;
            cnt++;
        }
    }
    int sum=1;
    for(int i=1;i<=n;i++){
        sum=(sum%P*i%P)%P;
    }
    cout<<sum<<endl;
    return 0;
}