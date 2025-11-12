#include <bits/stdc++.h>

using namespace std;

int n,m;
string a;
unsigned long long res;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    cin>>a;
    for(int i =0 ;i<n;i++){
        int temp=0;
        cin>>temp;
    }
    res =1;
    for(int i=n;i>1;i--){
        res*=i;
    }
    cout <<res%998244353;
    return 0;
}
