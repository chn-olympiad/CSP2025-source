#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5050],b[3050],c[3050],ans;
const ll inf=998244353;
const ll zero=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[0]=1;
    for(int j=1;j<a[1];j++) b[j]=1;
    for(int i=2;i<n;i++){
        if(i%2) b[0]=(c[0]+1)*2-1;
        else c[0]=(b[0]+1)*2-1;
        if(i%2){
            for(int j=1;j<=2050;j++){
                b[j]=c[j]+c[max(zero,j-a[i])];
                if(j<a[i]) b[j]++;
            }
            ans+=b[a[i+1]];
        }
        else{
            for(int j=1;j<=2050;j++){
                c[j]=b[j]+b[max(zero,j-a[i])];
                if(j<a[i]) c[j]++;
            }
            ans+=c[a[i+1]];
        }
    }
    cout<<ans%inf;
    return 0;
}
