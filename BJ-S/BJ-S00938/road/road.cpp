#include<bits/stdc++.h>
using namespace std;

int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  int a[100001],y[100001];
  int m,n,k,c,b,x,ad,add=0;
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++){
        cin>>c>>b>>a[i];
  }
  for(int i=1;i<=k;i++){
        cin>>x;
    for(int j=1;j<=k;j++){
        cin>>y[j];
        ad+=y[j];
    }
  }
  if(ad==0&&x==0){
    cout<<0;
    return 0;
  }

  sort(a,a+m);
  for(int i=1;i<=n;i++){
    add+=a[i];
  }
  cout<<add;
return 0;
}