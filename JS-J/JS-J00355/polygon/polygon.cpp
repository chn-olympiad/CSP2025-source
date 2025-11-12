#include<bits/stdc++.h>
using namespace std;
int a[1011011];
int p[1011211];
bool pd(int l,int r){
    int cnt=0;
    for(int i=l;i<=r;i++)cnt+=a[i];
    return cnt>a[r]*2;
}
int n,ans;
void work(int dep,int z,int ma){
    if(dep>n)return;
    for(int k=n;k>=ma+1;k--){
        if(z>a[k]){
         //   cout<<z<<' '<<a[k]<<' '<<dep+1<<endl;
            ans++;
        }
        z+=a[k];
        work(dep+1,z,k);
        z-=a[k];
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    if(n==3){
        sort(a+1,a+1+n);
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    sort(a+1,a+1+n);
    if(a[n]==1){
        cout<<(n-1)*(n-2)/2;
        return 0;
    }
     for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int x=a[i]+a[j];
          //  cout<<a[i]<<' '<<a[j]<<' '<<x<<endl<<endl;;
            work(2,x,j);
        }
    }
    cout<<ans;
    return 0;
}
