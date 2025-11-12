#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],c=0,p,l=1,r=2, h=3;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        c=c+i;
    }

    for(int j=(n-3)*3;j>=1;j--){
        for(int o=1;o<=n-2;o++){
            if(a[l]+a[r]>a[h]){
                p++;
                r++;
                h++;
            }else{
            r++;
            h++;
            }
            l++;
            r=l+1;
            h=r+1;
        }

    }







  cout<<p;

return 0;



}
