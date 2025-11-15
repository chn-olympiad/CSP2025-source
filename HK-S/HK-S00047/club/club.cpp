#include <bits/stdc++.h>
using namespace std;
int main(){
  ifstream f("club.in");
  ofstream g("club.out");
  int t,n,na,nb,nc,ans,poi;
  int a[100000],b[100000],c[100000],ocd[100000];
  f>>t;
  for (int j=0;j<t;j++){
    f>>n;
    ans=0;
    na=0;
    nb=0;
    nc=0;
    for (int i=0;i<n;i++){
      f>>a[i]>>b[i]>>c[i];
      if (a[i]>=b[i] && a[i]>=c[i]){
        na++;
        ocd[i]=a[i]-max(b[i],c[i]);
      }
      else if (b[i]>=a[i] && b[i]>=c[i]){
        nb++;
        ocd[i]=b[i]-max(a[i],c[i]);
      }
      else{
        nc++;
        ocd[i]=c[i]-max(a[i],b[i]);
      }
    }
    for (int i=0;i<n;i++){
      if (a[i]>=b[i] && a[i]>=c[i]){
        ans+=a[i];
        if (na<=n/2){
          ocd[i]=100000;
        }
      }
      else if (b[i]>=a[i] && b[i]>=c[i]){
        ans+=b[i];
        if (nb<=n/2){
          ocd[i]=100000;
        }
      }
      else{
        ans+=c[i];
        if (nc<=n/2){
          ocd[i]=100000;
        }
      }
    }
    sort(ocd,ocd+n);
    poi=0;
    while (ocd[poi]!=100000 && (na>n/2 || nb>n/2 || nc>n/2)){
        ans-=ocd[poi];
        poi++;
        na--;
        nb--;
        nc--;
    }
    g<<ans<<endl;
  }
}