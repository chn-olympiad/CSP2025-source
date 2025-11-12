#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("~/Desktop/replace/replace1.in","r",stdin);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    char a[200000];
    int b[100000];
    cin>>n>>m;
    cin>>a;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<n;i++){
        if(b[i]>i){
            ans=i-1;
        }
    }
    cout<<ans;
    return 0;
}