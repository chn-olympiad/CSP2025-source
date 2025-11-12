#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool A,B;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) A=1;
        if(a[i]!=0&&a[i]!=1) B=1;
    }
    if(A==0&&k==0){
        cout<<int(n/2)<<endl;
        return 0;
    }
    if(B==0&&k<=1){
        if(k==1){
            int cnt=0;
            for(int i=1;i<=n;i++)
                if(a[i]==1) cnt++;
            cout<<cnt<<endl;
        }
        if(k==0){
            int cnt1=0,cnt2=0,t=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0) cnt1++,t=0;
                else if(a[i]==1&&a[i-1]==1&&t==0) cnt2++,t=1;
            }
            cout<<cnt1+cnt2<<endl;
        }

        return 0;
    }
    int mx=-1;
    for(int i=1;i<=n-1;i++){
        int start=i;
        int sum=0,ans=0;
        for(int j=start;j<=n;j++){
            sum^=a[j];
            if(sum==k) ans++,sum=0;
        }
        mx=max(ans,mx);
    }
    cout<<mx<<endl;
    return 0;
}
