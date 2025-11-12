#include <iostream>
#include <algorithm>
using namespace std;
int n,a[5050],b[5050],cnt;
unsigned long long sum;
void calc(int i,int j){
    if(i==n){
        if(sum>b[j]*2)
            cnt=(cnt+1)%998244353;
        return;
    }
    sum+=a[i];
    b[j++]=max(b[j-2],a[i]);
    calc(i+1,j);
    j--;
    sum-=a[i];
    calc(i+1,j);
}
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    calc(0,1);
    if(n==3)
        cout<<((a[0]+a[1]+a[2]) > 2*max(max(a[0],a[1]),a[2]));
    else
        cout<<cnt;
    return 0;
}
