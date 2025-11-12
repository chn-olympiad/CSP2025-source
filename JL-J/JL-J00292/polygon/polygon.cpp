#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 int n,c=0,a[5002]={};
 cin>>n;
 for(int i=1;i<=n;i++){
    cin>>a[i];
 }
 for(int i=3;i<=n;i++){
    for(int j=1;j<=n;j++){
        if((a[i]+a[i+1]+a[i+2])>max(max(a[i+1],a[i]),a[i+2])*2) c++;
    }
 }
 cout<<c;
 fclose(stdin);
 fclose(stdout);
 return 0;
}
