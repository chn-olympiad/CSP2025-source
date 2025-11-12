#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N],b[N];
int cnta,cntb,cntc;
int maxx=-1,n;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]] ++;
    }
    int ans=1;
    for(int i=1;i<=500){
        if(b[i] != 0){
            ans *= b[i];
        }
    }
    
    return 0;
}
