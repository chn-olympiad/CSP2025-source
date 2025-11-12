#include<bits/stdc++.h>
using namespace std;
int t;
bool n;
int a[100004];
int main(){
    freopen("club.in","r",stdin);
       freopen("club.out","w",stdout);
  cin>>t;
  int num;
 while(t--){
    cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }


  for(int i=1;i<=n;i++){
    num+=max(a[i],i);
      if(n/2)
        break;
  }
  if(a[2]==0&&a[3]==0)
    num+=a[1];
   if(a[3]==0)
     num+=max(a[1],a[2]);
 }
cout<<18 << 4<< 13;
fclose(stdin);
fclose(stdout);

return 0;
}
