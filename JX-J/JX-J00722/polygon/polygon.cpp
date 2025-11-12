#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int a[N];
int n;
int faa(int x,int sum){
    int ans=0;
    if(sum>x) ans++;
    for(int i=1;i<=x-1;i++){
        int sum1=sum-a[i];
        if(sum1>x){
            ans++;
            for(int j=i+1;j<=n;j++){
                int w=j,sum2=sum1-a[j];
                while(sum2>x){
                    ans++;
                    j++;
                    sum2-=a[j];
                }
                j=w;
            }
        }
    }

    return ans;

}

signed main(){
     freopen("polygon.in","r",stdin);
     freopen("polygon.out","w",stdout);
     cin>>n;
     int sum=0;
     for(int i=1;i<=n;i++){
         cin>>a[i];
         sum+=a[i];
     }
     sort(a+1,a+n+1);
     int fa=0;
     for(int i=n;i>=1;i--){
         sum-=a[i];
         fa+=faa(a[i],sum);
     }
     cout<<fa;
     fclose(stdin);
     fclose(stdout);
     return 0;
}
