#include <bits/stdc++.h>
using namespace std;
int a[6005];int n;
int z=3,ans=0;
void d(int t,int num,int p){
     if(t==z){
       for(int i=num;i<n;i++){
            //cout<<a[i]<<endl;
            if(p+a[i]>a[i]*2) {
                ans++;
            }
        }
        return;
    }
    else{
      for(int i=num;i<n;i++){
            //cout<<a[i]<<" ";cout<<z<<"a"<<t<<endl;
            d(++t,i+1,p+a[i]);
            t--;
        }
        return;
    }

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(z=3;z<=n;z++){
        d(1,0,0);
    }
    printf("%d",ans%998244353);
    return 0;
}
