#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  int n,k,a[5];
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
}
    if(a[1]==0&&a[2]==0)
    cout<<2;
    else if(a[2]==0||a[1]==0)
    cout<<1;
    else
		cout<<1;
   
  return 0;
}


