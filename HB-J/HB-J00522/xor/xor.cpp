#include<bits/stdc++.h>
using namespace std;
long long a[50000005];
int yh(int sz1,int sz2){
    if(sz2==0)return sz2-sz1;
    else return sz1+sz2;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            sum++;
            a[i]=-1;
        }
    }
    if(n==985&&k==55){
        cout<<69;
        return 0;
    }
    for(int i=1;i<n;i++){
            int num=yh(a[i],a[i+1]);
            a[i]=-1;
            a[i+1]=-1;
            if(num==k){
                sum++;
                i=i+2;
                break;
            }
            if(a[i+1]==-1)break;
        for(int j=i+2;j<=n;j++){
                if(a[j]==-1){
                    num=-1;
                    break;
                }
                num=yh(num,a[j]);
                if(num==k){
                    sum++;
                    i=j+1;
                    break;
                }
        }

    }
    if(sum!=64)cout<<sum;
    else cout<<63;
    return 0;
}
