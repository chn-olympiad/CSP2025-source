#include<bits/stdc++.h>
using namespace std;
int n , m;
string s;
int a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int c = 0,ans=0;
    for(int i = 0;i<n;i++){
        if(s[i]==49&&a[i]!=505){
            ans++;
        }else if(s[i]==48){
            c++;
            for(int j = 0;j<n;j++){
                if(a[i]==c){
                    a[i]==505;
                }
            }
        }
    }
    cout<<ans%998244353<<endl;
    return 0;
}
