#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[5010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r;
    int sum=0;
    while(l<n-1){
        r=l+2;
        int s=0;
        int maxl=-1;
        while(r<n+1){

            for(int i=l;i<=r;i++){
                s+=a[i];
                maxl=max(maxl,a[i]);
            }
            maxl*=2;
            if(s>maxl){
                sum++;
            }
            r++;
        }
        l++;
    }
    cout<<sum;

    return 0;
}
