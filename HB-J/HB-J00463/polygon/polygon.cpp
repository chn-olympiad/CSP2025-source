#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,a[N],sum;
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}
  for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	  for(int k=j+1;k<=n;k++){
	    if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){sum++;}
      }
    }
  }
  cout<<sum;
  return 0;
}
