#include<bits/stdc++.h>
using namespace std;
int n,a[505],m;
string str;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>str;
    int nn = n;
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i] == 0){
            nn--;
        }
    }
    int ans = 1;
    for(int i=nn;i>0;i--){
        ans = ans * i % 998% 244% 353;
    }
    for(int i=n-nn;i>0;i--){
        ans = ans * i % 998% 244% 353;
    }
    cout<<ans;
    return 0;
}

