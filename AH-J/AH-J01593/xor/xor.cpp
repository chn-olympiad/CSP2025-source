#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0,nt=0;
int main(){
    freopen("xor4.in","r",stdin);
    freopen("xor4.out","w",stdout);
    cin>>n>>k;
    int a[500002],b[500002];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) cnt++;
        if(a[i]==0) nt++;
    }
    if(k==1){
        cout<<cnt;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==1&&a[i-1]==1){
                nt++;
                i++;
            }
        }
        cout<<nt;
    }
    return 0;
}
