#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n,a[100924],b[100924],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=2){
        cout<<"0";
    return 0;
    }

    sort(a+1,a+n);
    if(n==3){
        if(a[3]<a[1]+a[2])cout<<"1";
        else cout<<"0";
        return 0;
    }
    if(n==4){
        if(a[4]<a[2]+a[3]+a[1])ans++;
        if(a[4]<a[1]+a[2])ans++;
        if(a[4]<a[1]+a[3])ans++;
        if(a[4]<a[2]+a[3])ans++;
        if(a[3]<a[1]+a[2])ans++;
        cout<<ans;
        return 0;
    }
    if(n==4){
        if(a[4]<a[2]+a[3]+a[1])ans++;
        if(a[4]<a[1]+a[2])ans++;
        if(a[4]<a[1]+a[3])ans++;
        if(a[4]<a[2]+a[3])ans++;
        if(a[3]<a[1]+a[2])ans++;
        cout<<ans;
        return 0;
    }if(n==5){
        if(a[5]<a[2]+a[3]+a[1]+a[4])ans++;
        if(a[5]<a[2]+a[3]+a[1])ans++;
        if(a[5]<a[2]+a[4]+a[1])ans++;
        if(a[5]<a[4]+a[3]+a[1])ans++;
        if(a[5]<a[2]+a[4]+a[3])ans++;
        if(a[4]<a[2]+a[3]+a[1])ans++;

        if(a[5]<a[1]+a[2])ans++;
        if(a[5]<a[1]+a[3])ans++;
        if(a[5]<a[1]+a[4])ans++;
        if(a[5]<a[2]+a[3])ans++;
        if(a[5]<a[2]+a[4])ans++;
        if(a[5]<a[3]+a[4])ans++;

        if(a[4]<a[1]+a[2])ans++;
        if(a[4]<a[1]+a[3])ans++;
        if(a[4]<a[2]+a[3])ans++;
        if(a[3]<a[1]+a[2])ans++;

        cout<<ans;
        return 0;
    }
    for(int i=n;i>=1;i--)
        b[n-i+1]=a[i];
        //for(int i=1;i<=n;i++)cout<<b[i];
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(b[j]+b[j+1]>b[i])ans+=(n-i-2)*(n-i-1)/2+1;
            else if(b[j]+b[j+1]==b[i])ans+=(n-i-2)*(n-i-1)/2;
        }
    }
    cout<<ans;
}
