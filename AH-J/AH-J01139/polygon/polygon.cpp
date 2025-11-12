#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        return 0;
    }
    int cnt=0;
    if(n==4){
       if(a[1]+a[2]>a[3])cnt++;
       if(a[1]+a[2]>a[4])cnt++;
       if(a[1]+a[3]>a[4])cnt++;
       if(a[2]+a[3]>a[4])cnt++;
       if((a[1]+a[4])*2>2*a[4])cnt++;
    }else if(n==5){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    if(a[i]+a[j]>a[k])cnt++;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=j+1;k<=n;k++)
                    for(int l=k+1;l<=n;l++)
                        if(a[i]+a[j]+a[k]+a[l]>2*a[l])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5])cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
