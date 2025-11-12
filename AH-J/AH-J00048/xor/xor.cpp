#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1500005],maxx=0;
int main(void){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int cnt=0,sum=a[i];
        int j=i,l=0;
        while(j<=n){
            if(l!=0)
            {
                sum=sum xor a[j];
            }
            else l=1;
            j++;
            if(sum==k)
            {
                cnt++;
                sum=a[j];
                l=0;
            }
        }
        if(cnt>maxx)maxx=cnt;
    }
    cout<<maxx;
    return 0;
}
