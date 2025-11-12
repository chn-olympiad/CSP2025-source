#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],book[500005],cnt,flag=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {cin>>a[i]; if(a[i]>1)flag=0; if(a[i]==k) cnt++,book[i]=1;}
    if(flag=1){
        cout<<cnt; return;
    }
    for(int i=1;i<=n;i++){
        if(book[i]==1) continue;
        int it=a[i];
        for(int j=i+1;j<=n;j++){
            if(book[j]==1) break;
            it^=a[j];
            if(it==k){
                cnt++; for(int p=i;p<=j;p++) book[p]=1; break;
            }
        }
    }
    cout<<cnt;
}
