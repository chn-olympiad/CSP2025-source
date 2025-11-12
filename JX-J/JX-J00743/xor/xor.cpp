#include<bits/stdc++.h>
using namespace std;
int s[10001];
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==m){
            sum++;
        }
    }
    cout<<sum+1;
    return 0;
}
