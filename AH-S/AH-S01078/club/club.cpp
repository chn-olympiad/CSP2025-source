#include<bits/stdc++.h>
using namespace std;
long long y,n,w,sum=0,sum10=1,a,b1[100005],b2[100005],b3[100005],b4[100005],p=1,t=1,r=1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>y;
    for(long long i=1;i<=y;i++){
        cin>>n;
        a=n/2;
        for(long long j=1;j<=n;j++){
            cin>>b1[j]>>b2[j]>>b3[j];
        }
        sort(b1+1,b1+n+1);
        sort(b2+1,b2+n+1);
        sort(b3+1,b3+n+1);
        for(long long j=1;j<=a;j++){
            b4[sum10]=b1[j];
            sum10++;
            b4[sum10]=b2[j];
            sum10++;
            b4[sum10]=b3[j];
            sum10++;
        }
        sort(b4+1,b4+n+1);
        for(long long j=1;j<=a;j++){
            sum+=b4[j];
        }
		cout<<sum<<endl;
    }
    return 0;
}
