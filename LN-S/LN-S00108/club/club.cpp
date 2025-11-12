#include<bits/stdc++.h>
using namespace std;
long long a[100005][8];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n,sum=0;
    cin>>t;
    long long s[t+5];
    for(long long x=0;x<t;x++){
        s[x]=0;
        cin>>n;
        for(long long i=0;i<n;i++){
            sum=0;
            for(long long j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j]>sum){
                    sum=a[i][j];
                }
                s[x]+=sum;
            }
        }
    }
    for(long long x=0;x<t;x++){
        cout<<s[x]<<" ";
    }
    return 0;
}
