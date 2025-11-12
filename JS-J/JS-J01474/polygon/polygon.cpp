#include<bits/stdc++.h>
using namespace std;
const int N=1e3*5+10;
const long long M=998244353;
int n,a[N];
long long ans;
void test(int x,int y,int z,int k){
    if(k>=3 && y>z*2) ans=(ans+1)%M;
    for(int i=x+1;i<=n;i++){
        test(i,y+a[i],max(a[i],z),k+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    test(0,0,0,0);//xiabiao zonghe zuidazhi shuliang
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
