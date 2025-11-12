 #include <bits/stdc++.h>
 using namespace std;
 const int rx=1E7+10;
 int n[rx],a[rx],b[rx],c[rx];
 int t,m;
 int i,j,k,l;
 int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
 cin>>t;
 for (i=0;i<=t;i++){
     while (i>=1&&i<=5)
 {
   cin>>n[i];
   for (int j=1;j<=i;j++)
   cin>>a[j]>>b[j]>>c[j]>>endl;
     for(j=1;j<=i;j++)
     if (a[j]<=n/2&&b[j]<=n/2&&c[j]<=n/2&&a[j]+b[j]+c[j]=n[i])
     a[j][max]+b[j][max]+c[j][max]=m;
      }
      cout<<m;
 }
 return 0;
 }
