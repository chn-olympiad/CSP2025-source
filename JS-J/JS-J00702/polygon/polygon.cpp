#include<bits/stdc++.h>
using namespace std;
int a[10011];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n-1;i++){// zui da zhi shi a[i]
        for(int j=i+1;j<n;j++){//cong a[j] kai shi lei jia
            int num=1,sum=a[i];
            for(int k=j;k<n;k++){//
                sum+=a[k];
                num=k-i+1;
                for(int l=k+1;l<=n;l++){
                    int summ=sum;
                    summ+=a[l];
                    num++;
                    if(num>=3&&summ>a[i]*2){
                       // cout<<a[i]<<" "<<summ<<endl;
                        ans++;
                        ans%=998244353;
                    }
                }
            }
        }
    }

    cout<<ans+1<<endl;
    return 0;
}
