#include<bits/stdc++.h>
using namespace std;
int a[500005],ans;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);//.out!!!

    int n,k;
    cin>>n>>k;
    bool flag=1, flag0=1;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]!=1)flag=0;
        if(a[i]!=1&&a[i]!=0)flag0=0;
    }
    if(flag){
        if(k!=1&&k!=0){
            cout<<"0\n";
            return 0;
        }
        if(k==1){
            cout<<n<<"\n";
            return 0;
        }if(k==0){
            int ans=n;
            while(n){
                n/=2;
                ans+=n;
            }
            cout<<n;
            return 0;
        }
    }
    if(flag0){
        if(k!=1&&k!=0){
            cout<<"0\n";
            return 0;
        }
        int cnt0=0,cnt1=0,ans;
        for(int i=0;i<n;++i){
            if(a[i]==0)cnt0++;else cnt1++;
        }
        if(k==1){
            cout<<cnt1;
        }else{
            while(cnt1){
                cnt1/=2;
                ans+=cnt1;
            }
            cout<<cnt0+ans;
        }
    }
    /*for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            cout<<"ij: ";
            for(int k=i;k<=j;++k){
                cout<<a[k]<<' ';
            }cout<<endl;
            int xorn=a[i];
            for(int k=i+1;k<=j;++k){
                xorn^=a[k];
            }
            cout<<xorn<<endl;
            if(xorn==k)ans++,cout<<"ans: "<<ans<<endl;
        }
    }
    cout<<ans<<"\n";
    4 3
      2 1 0 3*/
    return 0;
}
