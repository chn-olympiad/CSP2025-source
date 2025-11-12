#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
    freopen("seat.in","w","stdin")
    freopen("seat.out","r","stdout")
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int f=1;
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[i]<a[j]){a[i]=a[j];f=j;}
        }
    }
    if(f==n*m) {cout<<n<<' '<<m;fclose("stdin") fclose("stdout") }
    if(f==1) {cout<<'1'<<' '<<'1';fclose("stdin") fclose("stdout") }
    int ans;
    if(f%n==0) ans=f/n;
    else ans=f/n+1;
    int sum;
    if(ans%2==0&&f%n==0) sum=1;
    else if(ans%2==0) sum=n-f%n+1;
    else if(ans%2!=0&&f%n==0) sum=n;
    else sum=f%n;
    cout<<ans<<' '<<sum;
    fclose("stdin")
    fclose("stdout")
    return 0;
}
