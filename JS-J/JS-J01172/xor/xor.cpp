#include<bits/stdc++.h>
using namespace std;
int a[500000+10];
int l[500000+10];
int r[500000+10];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,ans=0,idx=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int cnt=a[i];
        for(int j=i;j<n;j++){
            cnt=cnt^a[j];
            if(cnt==k){
                ans++;
                l[idx]=i;
                r[idx]=j;
                idx++;
            }
        }
    }
    for(int i=0;i<idx-1;i++){
        for(int j=i+1;j<idx;j++){
            if(l[i]>l[j]&&l[i]<r[j]||r[i]>l[j]&&r[i]<r[i]){
                ans-=2;
            }
        }
    }
    cout<<ans+1<<endl;
    return 0;
}