#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,num=0;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];    }
    for(int len=1;len<=n;len++){
        for(int beg=1;beg<=n-len+1;beg++){
            long long sum=0;
            for(int i=beg;i<=beg+len-1;i++){
                sum=(sum^a[i]);
            }
            if(sum==m){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
