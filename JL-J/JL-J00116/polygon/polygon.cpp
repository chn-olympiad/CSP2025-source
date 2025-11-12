#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],cnt,n;

int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   if(n==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if((i+k+j)>2*max(i,max(j,k))) cnt++;
                }
            }
        }
   }
   if(n==5){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if((i+k+j)>2*max(i,max(j,k))) cnt++;
                    for(int l=k+1;l<=n;i++){
                            if((i+k+j+l)>2*max(max(i,l),max(j,k))) cnt++;
                            for(int r=l+1;r<+n;r++)
                                    if((i+k+j+l+r)>2*max(max(max(i,l),max(j,k)),r)) cnt++;
                        }
                }
            }
        }
   }
   cout<<cnt%908244353;
   fclose(stdin);
   fclose(stdout);
}
