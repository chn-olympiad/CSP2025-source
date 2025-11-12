#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int ans;
int n,k,a[500010];
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int l=0;l<n;l++){
        for(int r=l+1;r<=n;r+=2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
