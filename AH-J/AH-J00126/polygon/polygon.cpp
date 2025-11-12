#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5005],cnt,b[5005];
int main(){
        freopen("polygon.in","r",stdin);
        freopen("polygon.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            int sum=a[i];
            int maxn=sum;
            for(int j=i+1;j<=n;j++){
               sum+=a[j];
               maxn=max(a[j],maxn);
               if(sum>maxn*2){
                    cnt++;
               }
            }
        }
        for(int i=1;i<=n;i++){
            int sum=a[i];
            int maxn=sum;
            for(int j=i+1;j<=n;j++){
               sum+=a[j];
               maxn=max(a[j],maxn);
               if(sum>maxn*2){
                    cnt++;
                    sum-=a[j];
               }
            }
        }
        for(int i=1;i<=5000;i++){
            if(b[i]>1){
                cnt-=b[i];
            }
        }
        cout<<cnt%998244353;
        fclose(stdin);
        fclose(stdout);
        return 0;
}
