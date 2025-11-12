#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,s[N];
bool vis[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k>1){
        cout<<0;
        return 0;
    }
    int cnt=0,lst=-1;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        if(k==0){
            if(lst==-1){
                if(t==k) cnt++,lst=-1;
                else lst=t;
            }else{
                if(t==k) cnt++,lst=-1;
                else if(lst==t) cnt++,lst=-1;
            }
        }else{
            if(t==k) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
