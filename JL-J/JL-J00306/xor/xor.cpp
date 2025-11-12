#include <bits/stdc++.h>
using namespace std;

const int N=5e5+7;

bool f1=1,f2=1;

int a[N],n,k;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!(a[i]==1)) f1=0;
        if(!(a[i]>=0&&a[i]<=1)) f2=0;
    }
    if(f1){
        if(k==0) cout<<n/2;
        else if(k==1) cout<<n;
        else cout<<0;
        return 0;
    }
    int cnt=0;
    int ii=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            //cout<<i<<" "<<j<<endl;
            int s=0;
            for(int p=i;p<=j;p++)
                s^=a[p];
            if(s==k){
                //cout<<i<<":"<<j<<endl;
                cnt++;
                i=j+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
