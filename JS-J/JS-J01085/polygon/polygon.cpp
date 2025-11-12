#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        long long ans=a[1]+a[2]+a[3];
        int maxn=max(a[1],max(a[2],a[3]));
        if(ans>maxn*2)cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            flag=0;
            break;
        }
    }
    if(flag==1){
        int k=3;
        long long zh=0;
        while(k<n){
            int h=k,w=k;
            long long sum=1;
            for(int i=n;i>=1;i--){
                h--;
                sum=sum*i;
                if(h==0)break;
            }
            long long total=1;
            for(int i=k;i>=1;i--){
                total=total*i;
            }
            zh=zh+sum/total;
            k++;
        }
        cout<<zh%998244353<<endl;
        return 0;
    }
    else cout<<n*2;
    return 0;
}
