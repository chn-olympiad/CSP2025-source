#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,jishu=0;
    cin>>n>>k;
    int a[n];
    for(long long i=0;i<n;i++)
        cin>>a[i];
    for(long long i=0;i<n;i++){
        int x=a[i];
        for(long long j=i;j<n;j++){
            a[i]==a[j]? x=a[i]:x=(x^a[j]);
            if(x==k){
                jishu++;
                i=j;
                break;
            }
        }
    }
    cout<<jishu;
    return 0;
}
