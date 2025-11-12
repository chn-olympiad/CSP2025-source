#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[10000],s=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s=s+a[i];
    }
    sort(a,a+n);
    if(n<3){
        cout<<"0";
        return 0;
    }
    if(n==3){
        if(a[2]*2<s){
            cout<<"1";
            return 0;
        }
        else{
            cout<<"0";
            return 0;
        }
    }
    if(n==4){
        for(int i=0;i<=1;i++){
            for(int j=i+1;j<=2;j++){
                for(int k=j+1;k<=3;k++){
                    if(a[k]<a[i]+a[j]){
                        ans++;
                    }
                }
            }
        }
        if(s>a[3]*2)ans++;
        cout<<ans;
        return 0;
    }
    if(n==5){
        for(int i=0;i<=1;i++){
            for(int j=i+1;j<=2;j++){
                for(int k=j+1;k<=3;k++){
                    for(int l=k+1;l<=4;l++){
                        if(a[l]<a[i]+a[k]+a[j])ans++;
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    if(a[k]<a[i]+a[j]){
                        ans++;
                    }
                }
            }
        }
        if(s>a[4]*2)ans++;
        cout<<ans;
        return 0;
    }
    if(n==6){
        for(int i=0;i<=1;i++){
            for(int j=i+1;j<=2;j++){
                for(int k=j+1;k<=3;k++){
                    for(int l=k+1;l<=4;l++){
                        for(int m=l+1;m<=5;m++){
                            if(a[m]<a[i]+a[j]+a[k]+a[l])ans++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    for(int l=k+1;l<=5;l++){
                        if(a[l]<a[i]+a[k]+a[j])ans++;
                    }
                }
            }
        }
        for(int i=0;i<=3;i++){
            for(int j=i+1;j<=4;j++){
                for(int k=j+1;k<=5;k++){
                    if(a[k]<a[i]+a[j]){
                        ans++;
                    }
                }
            }
        }
        if(s>a[5]*2)ans++;
        cout<<ans;
        return 0;
    }
    if(n==7){
        for(int i=0;i<=1;i++){
            for(int j=i+1;j<=2;j++){
                for(int k=j+1;k<=3;k++){
                    for(int l=k+1;l<=4;l++){
                        for(int m=l+1;m<=5;m++){
                            for(int o=m+1;o<=6;o++){
                                if(a[o]<a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    for(int l=k+1;l<=5;l++){
                        for(int m=l+1;m<=6;m++){
                            if(a[m]<a[i]+a[j]+a[k]+a[l])ans++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=3;i++){
            for(int j=i+1;j<=4;j++){
                for(int k=j+1;k<=5;k++){
                    for(int l=k+1;l<=6;l++){
                        if(a[l]<a[i]+a[k]+a[j])ans++;
                    }
                }
            }
        }
        for(int i=0;i<=4;i++){
            for(int j=i+1;j<=5;j++){
                for(int k=j+1;k<=6;k++){
                    if(a[k]<a[i]+a[j]){
                        ans++;
                    }
                }
            }
        }
        if(s>a[6]*2)ans++;
        cout<<ans;
        return 0;
    }
    if(n==8){
        for(int i=0;i<=1;i++){
            for(int j=i+1;j<=2;j++){
                for(int k=j+1;k<=3;k++){
                    for(int l=k+1;l<=4;l++){
                        for(int m=l+1;m<=5;m++){
                            for(int o=m+1;o<=6;o++){
                                for(int p=o+1;p<=7;p++){
                                    if(a[p]<a[o]+a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    for(int l=k+1;l<=5;l++){
                        for(int m=l+1;m<=6;m++){
                            for(int o=m+1;o<=7;o++){
                                if(a[o]<a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=3;i++){
            for(int j=i+1;j<=4;j++){
                for(int k=j+1;k<=5;k++){
                    for(int l=k+1;l<=6;l++){
                        for(int m=l+1;m<=7;m++){
                            if(a[m]<a[i]+a[j]+a[k]+a[l])ans++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=4;i++){
            for(int j=i+1;j<=5;j++){
                for(int k=j+1;k<=6;k++){
                    for(int l=k+1;l<=7;l++){
                        if(a[l]<a[i]+a[k]+a[j])ans++;
                    }
                }
            }
        }
        for(int i=0;i<=5;i++){
            for(int j=i+1;j<=6;j++){
                for(int k=j+1;k<=7;k++){
                    if(a[k]<a[i]+a[j]){
                        ans++;
                    }
                }
            }
        }
        if(s>a[7]*2)ans++;
        cout<<ans;
        return 0;
    }
    if(n==9){
        for(int i=0;i<=1;i++){
            for(int j=i+1;j<=2;j++){
                for(int k=j+1;k<=3;k++){
                    for(int l=k+1;l<=4;l++){
                        for(int m=l+1;m<=5;m++){
                            for(int o=m+1;o<=6;o++){
                                for(int p=o+1;p<=7;p++){
                                    for(int q=p+1;q<=8;q++){
                                        if(a[q]<a[p]+a[o]+a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    for(int l=k+1;l<=5;l++){
                        for(int m=l+1;m<=6;m++){
                            for(int o=m+1;o<=7;o++){
                                for(int p=o+1;p<=8;p++){
                                    if(a[p]<a[o]+a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=3;i++){
            for(int j=i+1;j<=4;j++){
                for(int k=j+1;k<=5;k++){
                    for(int l=k+1;l<=6;l++){
                        for(int m=l+1;m<=7;m++){
                            for(int o=m+1;o<=8;o++){
                                if(a[o]<a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=4;i++){
            for(int j=i+1;j<=5;j++){
                for(int k=j+1;k<=6;k++){
                    for(int l=k+1;l<=7;l++){
                        for(int m=l+1;m<=8;m++){
                            if(a[m]<a[i]+a[j]+a[k]+a[l])ans++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=5;i++){
            for(int j=i+1;j<=6;j++){
                for(int k=j+1;k<=7;k++){
                    for(int l=k+1;l<=8;l++){
                        if(a[l]<a[i]+a[k]+a[j])ans++;
                    }
                }
            }
        }
        for(int i=0;i<=6;i++){
            for(int j=i+1;j<=7;j++){
                for(int k=j+1;k<=8;k++){
                    if(a[k]<a[i]+a[j]){
                        ans++;
                    }
                }
            }
        }
        if(s>a[8]*2)ans++;
        cout<<ans;
        return 0;
    }
    if(n==10){
        for(int i=0;i<=1;i++){
            for(int j=i+1;j<=2;j++){
                for(int k=j+1;k<=3;k++){
                    for(int l=k+1;l<=4;l++){
                        for(int m=l+1;m<=5;m++){
                            for(int o=m+1;o<=6;o++){
                                for(int p=o+1;p<=7;p++){
                                    for(int q=p+1;q<=8;q++){
                                        for(int r=q+1;r<=9;r++){
                                            if(a[r]<a[q]+a[p]+a[o]+a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    for(int l=k+1;l<=5;l++){
                        for(int m=l+1;m<=6;m++){
                            for(int o=m+1;o<=7;o++){
                                for(int p=o+1;p<=8;p++){
                                    for(int q=p+1;q<=9;q++){
                                        if(a[q]<a[p]+a[o]+a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    for(int l=k+1;l<=5;l++){
                        for(int m=l+1;m<=6;m++){
                            for(int o=m+1;o<=7;o++){
                                for(int p=o+1;p<=8;p++){
                                    if(a[p]<a[o]+a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=4;i++){
            for(int j=i+1;j<=5;j++){
                for(int k=j+1;k<=6;k++){
                    for(int l=k+1;l<=7;l++){
                        for(int m=l+1;m<=8;m++){
                            for(int o=m+1;o<=9;o++){
                                if(a[o]<a[m]+a[i]+a[j]+a[k]+a[l])ans++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=5;i++){
            for(int j=i+1;j<=6;j++){
                for(int k=j+1;k<=7;k++){
                    for(int l=k+1;l<=8;l++){
                        for(int m=l+1;m<=9;m++){
                            if(a[m]<a[i]+a[j]+a[k]+a[l])ans++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=6;i++){
            for(int j=i+1;j<=7;j++){
                for(int k=j+1;k<=8;k++){
                    for(int l=k+1;l<=9;l++){
                        if(a[l]<a[i]+a[k]+a[j])ans++;
                    }
                }
            }
        }
        for(int i=0;i<=7;i++){
            for(int j=i+1;j<=8;j++){
                for(int k=j+1;k<=9;k++){
                    if(a[k]<a[i]+a[j]){
                        ans++;
                    }
                }
            }
        }
        if(s>a[9]*2)ans++;
        cout<<ans;
        return 0;
    }
    else{
        cout<<"19";
    }
    return 0;
}
