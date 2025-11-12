#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int n;
int a[N];
int b[N];
int c[N];
int cnt;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0<<endl;
        return 0;
    }else{
        if(n==3){
            if((a[1]+a[2]+a[3])>(a[3]*2)){
                cout<<1<<endl;
                return 0;
            }else{
                cout<<0<<endl;
                return 0;
            }
        }else{
            for(int i=1;i<=n;i++){
                a[i]+=a[i-1];
            }
            for(int i=n;i>=3;i--){
                for(int j=i-1;j>=2;j--){
                    for(int k=1;;k++){
                        if(j==k){
                            break;
                        }else{
                            if((a[j]-a[k]+c[k])>c[i]){
                                for(int l=k;l<=j;l++){
                                    cout<<c[l]<<' ';
                                }
                                cout<<c[i]<<endl;
                                b[i]=((b[i]+1)%998244353);
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cnt=((cnt+b[i])%998244353);
    }
    cout<<cnt<<endl;
    return 0;
}
