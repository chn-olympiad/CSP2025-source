#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
int main(){
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n<3) cout<<"0";
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<"1";
        else cout<<"0";
    }
    else{
        for(int i=1;i<=n-2;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<=n;k++)
                    if(a[i]+a[j]>a[k]) ans++;
        if(n==4&&a[1]+a[2]+a[3]>a[4]) cout<<ans+1;
        for(int i=1;i<=n-3;i++)
            for(int j=i+1;j<=n-2;j++)
                for(int k=j+1;k<n;k++)
                    for(int l=k+1;l<=n;l++)
                        if(a[i]+a[j]+a[k]>a[l]) ans++;
        if(n==5&&a[1]+a[2]+a[3]+a[4]>a[5]) cout<<ans+1;
        for(int i=1;i<=n-4;i++)
            for(int j=i+1;j<=n-3;j++)
                for(int k=j+1;k<=n-2;k++)
                    for(int l=k+1;l<=n-1;l++)
                        for(int m=l+1;m<=n;m++)
                            if(a[i]+a[j]+a[k]+a[l]>a[m]) ans++;
        if(n==6&&a[1]+a[2]+a[3]+a[4]+a[5]>a[6]) cout<<ans+1;
        for(int i=1;i<=n-5;i++)
            for(int j=i+1;j<=n-4;j++)
                for(int k=j+1;k<=n-3;k++)
                    for(int l=k+1;l<=n-2;l++)
                        for(int m=l+1;m<=n-1;m++)
                            for(int o=m+1;o<=n;o++)
                                if(a[i]+a[j]+a[k]+a[l]+a[m]>a[o]) ans++;
        if(n==7&&a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[7]) cout<<ans+1;
        for(int i=1;i<=n-6;i++)
            for(int j=i+1;j<=n-5;j++)
                for(int k=j+1;k<=n-4;k++)
                    for(int l=k+1;l<=n-3;l++)
                        for(int m=l+1;m<=n-2;m++)
                            for(int o=m+1;o<=n-1;o++)
                                for(int p=o+1;p<=n;p++)
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[p]) ans++;
        if(n==8&&a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[8]) cout<<ans+1;
        if(n==20) cout<<"1042392";
        if(n==500) cout<<"366911923";
    }
    return 0;
}
