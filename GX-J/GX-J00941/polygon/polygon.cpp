#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int a[N],sum[N];
int n,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                int maxn=INT_MIN,m=0;
            for(int k=i;k<=j;k++){
                maxn=max(maxn,a[k]);
                m+=a[k];
            }
            if(m>2*maxn){
                cnt++;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<cnt;
    return 0;
}
