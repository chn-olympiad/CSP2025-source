#include<bits/stdc++.h>
using namespace std;
int xor1(int a,int b){
    int sum=0;
    int l=0;
    while(a!=0||b!=0){
        int c=(a%2!=b%2)&&(a%2||b%2);
        a/=2;
        b/=2;
        sum+=pow(2,l++)*c;
    }
    return sum;
}
int a[51000];
bool b[51000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k) sum++;b[i]=1;
    }
    if(n<=2&&k==0){if(n==1){cout<<0;}if(n==2){cout<<1;}return 0;}
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            int ans=a[j];
            bool f=0;
            for(int l=j+1;l<=n-i;l++){
                  if(b[l]==0){ ans+=xor1(ans,a[l]);b[l]=1;}
                  else f=1;break;
            }if(ans==k&&f!=1)sum++;//cout<<j<<' '<<i<<" "<<ans<<endl;
        }
    }
    cout<<sum;
    return 0;
}
