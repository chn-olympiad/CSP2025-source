#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll n,k,a[N],sum[N],maxv,l,cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]^a[i];}
    for(int i=1;i<=n;){
        bool flag=0;
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                cnt++;
                flag=1;
                i=j+1;
                break;
            }
        }
        if(!flag)i++;
    }
    cout<<cnt<<endl;
    return 0;
}
