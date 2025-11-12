#include<bits/stdc++.h>
using namespace std;
long long n,b[4][100924],aa=0;
long long s(long long ans,long long i,long long a1,long long a2,long long a3){
    if(i==n){return ans;}
    if(a1<n/2)aa=max(aa,s(ans+b[i+1][1],i+1,a1+1,a2,a3));
    if(a2<n/2)aa=max(aa,s(ans+b[i+1][2],i+1,a1,a2+1,a3));
    if(a3<n/2)aa=max(aa,s(ans+b[i+1][3],i+1,a1,a2,a3+1));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(long long p=0;p<t;p++){
    cin>>n;
    for(int j=1;j<=n;j++)
    for(int i=1;i<=3;i++)
        cin>>b[j][i];

    cout<<s(0,0,0,0,0)<<endl;
    aa=0;
}
return 0;
}

