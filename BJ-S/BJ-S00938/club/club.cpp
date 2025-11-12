#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
    int n;
cin>>n;
while(n--){
  int m=0,m1=0,m2=0,m3=0,anss=0;
  int ans[10],x[10];
  cin>>m;
  int a[1001],b[1001],c[1001];

  for(int i=0;i<m;i++){
    cin>>a[i]>>b[i]>>c[i];
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<3;j++){
        int maxx=0;
        if(a[i]>maxx)
            maxx=a[i];
        if(b[i]>maxx)
            maxx=b[i];
        if(c[i]>maxx)
            maxx=c[i];
            ans[i]=maxx;
    }
    for(int i=0;i<m;i++)
        anss+=ans[i];
    cout<<anss<<endl;
  }
}
return 0;
}