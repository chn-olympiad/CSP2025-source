#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (n<=2){
        cout<<0;
    }
    else if (n==3){
        sort(a+1,a+n+1);
        if (a[1]+a[2]>a[3]){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    else if (n==4){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==5){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==6){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==7){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==8){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==9){
       sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==10){
       sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==11){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==12){
       sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==13){
       sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==14){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c>c*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==15){
               sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c>c*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v>v*2){
                                                                        ans++;
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==16){
               sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c>c*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v>v*2){
                                                                        ans++;
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b>b*2){
                                                                            ans++;
                                                                        }
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==17){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c>c*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v>v*2){
                                                                        ans++;
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b>b*2){
                                                                            ans++;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m>m*2){
                                                                                ans++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==18){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c>c*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v>v*2){
                                                                        ans++;
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b>b*2){
                                                                            ans++;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m>m*2){
                                                                                ans++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            for (int qq=m+1;qq<=n;qq++){
                                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m+qq>qq*2){
                                                                                    ans++;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==19){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c>c*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v>v*2){
                                                                        ans++;
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b>b*2){
                                                                            ans++;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m>m*2){
                                                                                ans++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            for (int qq=m+1;qq<=n;qq++){
                                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m+qq>qq*2){
                                                                                    ans++;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            for (int qq=m+1;qq<=n;qq++){
                                                                                for (int ww=qq+1;ww<=n;ww++){
                                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m+qq+ww>ww*2){
                                                                                        ans++;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    else if (n==20){
        sort(a+1,a+n+1);
        long long ans=0;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    if (i+j>k && i+k>j && j+k>i){
                        ans++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        if (i+j+k+z>z*2){
                            ans++;
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            if (i+j+k+z+p>p*2){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                if (i+j+k+z+p+q>q*2){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    if (i+j+k+z+p+q+o>o*2){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        if (i+j+k+z+p+q+o+u>u*2){
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            if (i+j+k+z+p+q+o+u+t>t*2){
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                if (i+j+k+z+p+q+o+u+t+w>w*2){
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    if (i+j+k+z+p+q+o+u+t+w+l>l*2){
                                                        ans++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        if (i+j+k+z+p+q+o+u+t+w+l+h>h*2){
                                                            ans++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x>x*2){
                                                                ans++;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c>c*2){
                                                                    ans++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v>v*2){
                                                                        ans++;
                                                                    }
                                                                }

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b>b*2){
                                                                            ans++;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m>m*2){
                                                                                ans++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            for (int qq=m+1;qq<=n;qq++){
                                                                                if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m+qq>qq*2){
                                                                                    ans++;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            for (int qq=m+1;qq<=n;qq++){
                                                                                for (int ww=qq+1;ww<=n;ww++){
                                                                                    if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m+qq+ww>ww*2){
                                                                                        ans++;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    for (int z=k+1;z<=n;z++){
                        for (int p=z+1;p<=n;p++){
                            for (int q=p+1;q<=n;q++){
                                for (int o=q+1;o<=n;o++){
                                    for (int u=o+1;u<=n;u++){
                                        for (int t=u+1;t<=n;t++){
                                            for (int w=t+1;w<=n;w++){
                                                for (int l=w+1;l<=n;l++){
                                                    for (int h=l+1;h<=n;h++){
                                                        for (int x=h+1;x<=n;x++){
                                                            for (int c=x+1;c<=n;c++){
                                                                for (int v=c+1;v<=n;v++){
                                                                    for (int b=v+1;b<=n;b++){
                                                                        for (int m=b+1;m<=n;m++){
                                                                            for (int qq=m+1;qq<=n;qq++){
                                                                                for (int ww=qq+1;ww<=n;ww++){
                                                                                    for (int ee=ww+1;ee<=n;ee++){
                                                                                        if (i+j+k+z+p+q+o+u+t+w+l+h+x+c+v+b+m+qq+ww+ee>ee*2){
                                                                                            ans++;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans%998244353;
    }
    return 0;
}
