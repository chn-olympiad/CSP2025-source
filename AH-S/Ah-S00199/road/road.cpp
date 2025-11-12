#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  int n,m,k,c=0;
  cin >> n >> m >> k;
  long long u[m],v[m],w[m],a[n];
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i]>> w[i];
  }
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(w,w+m);
  for(int i=0;i<m-1;i++){
    c+=w[i];
  }
  cout << c;
  return 0;
}
