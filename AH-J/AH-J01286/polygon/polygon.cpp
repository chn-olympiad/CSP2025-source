#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    long long num=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n>=3){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j+1<=n;++j){
                for(int b=j+1;b<=n;++b){
                    if(a[i]+a[j]>a[b]){
                        num=(num+1)%998244353;
                    }
                }
            }
        }
    }
    if(n>=4){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j+1<=n;++j){
                for(int b=j+1;b+1<=n;++b){
                    for(int c=b+1;c<=n;++c){
                        if(a[i]+a[b]+a[j]>a[c]){
                            num=(num+1)%998244353;
                        }
                    }
                }
            }
        }
    }
    if(n>=5){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j+1<=n;++j){
                for(int b=j+1;b+1<=n;++b){
                    for(int c=b+1;c+1<=n;++c){
                        for(int d=c+1;d<=n;++d){
                            if(a[i]+a[c]+a[b]+a[j]>a[d]){
                                num=(num+1)%998244353;
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=6){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j+1<=n;++j){
                for(int b=j+1;b+1<=n;++b){
                    for(int c=b+1;c+1<=n;++c){
                        for(int d=c+1;d+1<=n;++d){
                            for(int e=d+1;e<=n;++e){
                                if(a[i]+a[c]+a[b]+a[d]+a[j]>a[e]){
                                    num=(num+1)%998244353;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=7){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j+1<=n;++j){
                for(int b=j+1;b+1<=n;++b){
                    for(int c=b+1;c+1<=n;++c){
                        for(int d=c+1;d+1<=n;++d){
                            for(int e=d+1;e+1<=n;++e){
                                for(int f=e+1;f<=n;++f){
                                    if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]>a[f]){
                                        num=(num+1)%998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=8){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g<=n;g++){
                                        if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]>a[g]){
                                            num=(num+1)%998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=9){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h<=n;h++){
                                            if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]>a[h]){
                                                num=(num+1)%998244353;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=10){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k<=n;k++){
                                                if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]>a[k]){
                                                    num=(num+1)%998244353;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=20){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            for(int p=o+1;p+1<=n;p++){
                                                                for(int q=p+1;q+1<=n;q++){
                                                                    for(int r=q+1;r+1<=n;r++){
                                                                        for(int s=r+1;s+1<=n;s++){
                                                                            for(int t=s+1;t+1<=n;t++){
                                                                                for(int u=t+1;u+1<=n;u++){
                                                                                    for(int v=+1;v+1<=n;v++){
                                                                                        if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]>a[v]){
                                                                                            num=(num+1)%998244353;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=19){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            for(int p=o+1;p+1<=n;p++){
                                                                for(int q=p+1;q+1<=n;q++){
                                                                    for(int r=q+1;r+1<=n;r++){
                                                                        for(int s=r+1;s+1<=n;s++){
                                                                            for(int t=s+1;t+1<=n;t++){
                                                                                for(int u=t+1;u+1<=n;u++){
                                                                                    if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]>a[u]){
                                                                                        num=(num+1)%998244353;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=18){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            for(int p=o+1;p+1<=n;p++){
                                                                for(int q=p+1;q+1<=n;q++){
                                                                    for(int r=q+1;r+1<=n;r++){
                                                                        for(int s=r+1;s+1<=n;s++){
                                                                            for(int t=s+1;t+1<=n;t++){
                                                                                if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>a[t]){
                                                                                    num=(num+1)%998244353;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=17){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            for(int p=o+1;p+1<=n;p++){
                                                                for(int q=p+1;q+1<=n;q++){
                                                                    for(int r=q+1;r+1<=n;r++){
                                                                        for(int s=r+1;s+1<=n;s++){
                                                                            if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>a[s]){
                                                                                    num=(num+1)%998244353;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=16){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            for(int p=o+1;p+1<=n;p++){
                                                                for(int q=p+1;q+1<=n;q++){
                                                                    for(int r=q+1;r+1<=n;r++){
                                                                        if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>a[r]){
                                                                                num=(num+1)%998244353;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=15){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            for(int p=o+1;p+1<=n;p++){
                                                                for(int q=p+1;q+1<=n;q++){
                                                                    if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]+a[o]+a[p]>a[q]){
                                                                        num=(num+1)%998244353;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=14){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            for(int p=o+1;p+1<=n;p++){
                                                                if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]+a[o]>a[p]){
                                                                    num=(num+1)%998244353;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=13){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        for(int o=+1;o+1<=n;o++){
                                                            if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]+a[l]+a[m]>a[o]){
                                                                num=(num+1)%998244353;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n>=11){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j+1<=n;j++){
                for(int b=j+1;b+1<=n;b++){
                    for(int c=b+1;c+1<=n;c++){
                        for(int d=c+1;d+1<=n;d++){
                            for(int e=d+1;e+1<=n;e++){
                                for(int f=e+1;f+1<=n;f++){
                                    for(int g=f+1;g+1<=n;g++){
                                        for(int h=g+1;h+1<=n;h++){
                                            for(int k=h+1;k+1<=n;k++){
                                                for(int l=+1;l+1<=n;l++){
                                                    for(int m=+1;m+1<=n;m++){
                                                        if(a[i]+a[c]+a[b]+a[d]+a[j]+a[e]+a[f]+a[g]+a[h]+a[k]>a[l]){
                                                            num=(num+1)%998244353;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<num;//lmnopqrstuvwxyz
    return 0;
}
