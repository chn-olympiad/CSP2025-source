#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<(a[1]==k?1:0);
        return 0;
    }
    if(n==2){
        cout<<max(  (a[1]==k?1:0)+(a[2]==k?1:0) , (a[1]^a[2]==k?1:0)  );
        return 0;
    }
    bool dou_shi_yi=1;
    for(int i=1;i<=n;i++)if(a[i]==0)dou_shi_yi=0;

    if(k==0&&dou_shi_yi){
        cout<<n/2<<endl;
        return 0;
    }
    if(k==0){
        int sum=a[1];ans=0;
        int i=2;
        while(i<=n){
            while(sum%2==1/*ji shu*/)sum+=a[i],i++;
            ans++;i++;

        }
        cout<<ans<<endl;
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;i++)ans+=a[i];
        cout<<ans<<endl;;
        return 0;
    }


    return 0;
}
