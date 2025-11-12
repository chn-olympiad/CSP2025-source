#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
        return 0;
    }
    int sum=0;
    if(n==4){
        sum+=(a[1]+a[2]>a[3]);
        sum+=(a[1]+a[2]>a[4]);

        sum+=(a[2]+a[3]>a[4]);

        sum+=(a[1]+a[2]+a[3]>a[4]);
        cout<<sum;
        return 0;
    }
    if(n==5){
        sum+=(a[1]+a[2]>a[3]);
        sum+=(a[1]+a[2]>a[4]);
        sum+=(a[1]+a[2]>a[5]);
        sum+=(a[1]+a[3]>a[4]);
        sum+=(a[1]+a[3]>a[5]);
        sum+=(a[1]+a[4]>a[5]);

        sum+=(a[2]+a[3]>a[4]);
        sum+=(a[2]+a[3]>a[5]);
        sum+=(a[2]+a[4]>a[5]);

        sum+=(a[3]+a[4]>a[5]);

        sum+=(a[1]+a[2]+a[3]>a[4]);
        sum+=(a[1]+a[2]+a[3]>a[5]);
        sum+=(a[1]+a[2]+a[4]>a[5]);
        sum+=(a[1]+a[3]+a[4]>a[5]);

        sum+=(a[2]+a[3]+a[4]>a[5]);

        sum+=(a[1]+a[2]+a[3]+a[4]>a[5]);
        cout<<sum;
        return 0;
    }
    if(n==6){
        sum+=(a[1]+a[2]>a[3]);
        sum+=(a[1]+a[2]>a[4]);
        sum+=(a[1]+a[2]>a[5]);
        sum+=(a[1]+a[2]>a[6]);
        sum+=(a[1]+a[3]>a[4]);
        sum+=(a[1]+a[3]>a[5]);
        sum+=(a[1]+a[3]>a[6]);
        sum+=(a[1]+a[4]>a[5]);
        sum+=(a[1]+a[4]>a[6]);

        sum+=(a[2]+a[3]>a[4]);
        sum+=(a[2]+a[3]>a[5]);
        sum+=(a[2]+a[3]>a[6]);
        sum+=(a[3]+a[4]>a[5]);
        sum+=(a[3]+a[4]>a[6]);
        sum+=(a[3]+a[5]>a[6]);

        sum+=(a[4]+a[5]>a[6]);

        sum+=(a[1]+a[2]+a[3]>a[4]);
        sum+=(a[1]+a[2]+a[3]>a[5]);
        sum+=(a[1]+a[2]+a[3]>a[6]);
        sum+=(a[1]+a[2]+a[4]>a[5]);
        sum+=(a[1]+a[2]+a[4]>a[6]);
        sum+=(a[1]+a[3]+a[4]>a[5]);
        sum+=(a[1]+a[3]+a[4]>a[6]);
        sum+=(a[1]+a[4]+a[5]>a[6]);

        sum+=(a[2]+a[3]+a[4]>a[5]);
        sum+=(a[2]+a[3]+a[4]>a[6]);
        sum+=(a[2]+a[3]+a[5]>a[6]);
        sum+=(a[2]+a[4]+a[5]>a[6]);

        sum+=(a[3]+a[4]+a[5]>a[6]);

        sum+=(a[1]+a[2]+a[3]+a[4]>a[5]);
        sum+=(a[1]+a[2]+a[3]+a[4]>a[6]);
        sum+=(a[1]+a[2]+a[3]+a[5]>a[6]);
        sum+=(a[1]+a[2]+a[4]+a[5]>a[6]);
        sum+=(a[1]+a[3]+a[4]+a[5]>a[6]);

        sum+=(a[2]+a[3]+a[4]+a[5]>a[6]);
        cout<<sum;
        return 0;
    }
    if(n==7){
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) if(a[i]+a[j]>a[k]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) if(a[i]+a[j]+a[k]>a[l]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) if(a[i]+a[j]+a[k]+a[l]>a[p]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) if(a[i]+a[j]+a[k]+a[l]+a[p]>a[o]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>a[u]) sum++;
        cout<<sum;
        return 0;
    }
    if(n==8){
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) if(a[i]+a[j]>a[k]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) if(a[i]+a[j]+a[k]>a[l]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) if(a[i]+a[j]+a[k]+a[l]>a[p]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) if(a[i]+a[j]+a[k]+a[l]+a[p]>a[o]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>a[u]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) for(int y=u+1;y<=n;y++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]>a[y]) sum++;
        cout<<sum;
        return 0;
    }
    if(n==9){
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) if(a[i]+a[j]>a[k]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) if(a[i]+a[j]+a[k]>a[l]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) if(a[i]+a[j]+a[k]+a[l]>a[p]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) if(a[i]+a[j]+a[k]+a[l]+a[p]>a[o]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>a[u]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) for(int y=u+1;y<=n;y++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]>a[y]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) for(int y=u+1;y<=n;y++) for(int t=y+1;t<=n;t++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[y]>a[t]) sum++;
        cout<<sum;
        return 0;
    }
    if(n==10){
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) if(a[i]+a[j]>a[k]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) if(a[i]+a[j]+a[k]>a[l]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) if(a[i]+a[j]+a[k]+a[l]>a[p]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) if(a[i]+a[j]+a[k]+a[l]+a[p]>a[o]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>a[u]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) for(int y=u+1;y<=n;y++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]>a[y]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) for(int y=u+1;y<=n;y++) for(int t=y+1;t<=n;t++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[y]>a[t]) sum++;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int l=k+1;l<=n;l++) for(int p=l+1;p<=n;p++) for(int o=p+1;o<=n;o++) for(int u=o+1;u<=n;u++) for(int y=u+1;y<=n;y++) for(int t=y+1;t<=n;t++) for(int r=t+1;r<=n;r++) if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[y]+a[t]>a[r]) sum++;
        cout<<sum;
        return 0;
    }
    return 0;
}
