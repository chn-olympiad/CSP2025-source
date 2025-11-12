#include<bits/stdc++.h>
using namespace std;
int nn,aa[50];
int f3(){
	int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
				if(aa[a]+aa[b]>aa[c]){
                    ans=(ans+1)%998244353;
				}
            }
        }
    }
    return ans;
}
int f4(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    if(aa[a]+aa[b]+aa[c]>aa[d]){
                        ans=(ans+1)%998244353;
                    }
                }
            }
        }
    }
    return ans;
}
int f5(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        if(aa[a]+aa[b]+aa[c]+aa[d]>aa[e]){
                            ans=(ans+1)%998244353;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f6(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]>aa[f]){
                                ans=(ans+1)%998244353;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f7(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]>aa[g]){
                                    ans=(ans+1)%998244353;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f8(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]>aa[h]){
                                        ans=(ans+1)%998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f9(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]>aa[i]){
                                            ans=(ans+1)%998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f10(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]>aa[j]){
                                                ans=(ans+1)%998244353;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f11(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]>aa[k]){
                                                    ans=(ans+1)%998244353;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f12(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]>aa[l]){
                                                        ans=(ans+1)%998244353;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f13(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]>aa[m]){
                                                            ans=(ans+1)%998244353;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f14(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        for(int n=m+1;n<=nn;n++){
                                                            if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]+aa[m]>aa[n]){
                                                                ans=(ans+1)%998244353;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f15(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        for(int n=m+1;n<=nn;n++){
                                                            for(int o=n+1;o<=nn;o++){
                                                                if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]+aa[m]+aa[n]>aa[o]){
                                                                    ans=(ans+1)%998244353;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f16(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        for(int n=m+1;n<=nn;n++){
                                                            for(int o=n+1;o<=nn;o++){
                                                                for(int p=o+1;p<=nn;p++){
                                                                    if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]+aa[m]+aa[n]+aa[o]>aa[p]){
                                                                        ans=(ans+1)%998244353;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f17(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        for(int n=m+1;n<=nn;n++){
                                                            for(int o=n+1;o<=nn;o++){
                                                                for(int p=o+1;p<=nn;p++){
                                                                    for(int q=p+1;q<=nn;q++){
                                                                        if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]+aa[m]+aa[n]+aa[o]+aa[p]>aa[q]){
                                                                            ans=(ans+1)%998244353;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f18(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        for(int n=m+1;n<=nn;n++){
                                                            for(int o=n+1;o<=nn;o++){
                                                                for(int p=o+1;p<=nn;p++){
                                                                    for(int q=p+1;q<=nn;q++){
                                                                        for(int r=q+1;r<=nn;r++){
                                                                            if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]+aa[m]+aa[n]+aa[o]+aa[p]+aa[q]>aa[r]){
                                                                                ans=(ans+1)%998244353;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f19(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        for(int n=m+1;n<=nn;n++){
                                                            for(int o=n+1;o<=nn;o++){
                                                                for(int p=o+1;p<=nn;p++){
                                                                    for(int q=p+1;q<=nn;q++){
                                                                        for(int r=q+1;r<=nn;r++){
                                                                            for(int s=r+1;s<=nn;s++){
                                                                                if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]+aa[m]+aa[n]+aa[o]+aa[p]+aa[q]+aa[r]>aa[s]){
                                                                                    ans=(ans+1)%998244353;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int f20(){
    int ans=0;
    for(int a=1;a<=nn;a++){
        for(int b=a+1;b<=nn;b++){
            for(int c=b+1;c<=nn;c++){
                for(int d=c+1;d<=nn;d++){
                    for(int e=d+1;e<=nn;e++){
                        for(int f=e+1;f<=nn;f++){
                            for(int g=f+1;g<=nn;g++){
                                for(int h=g+1;h<=nn;h++){
                                    for(int i=h+1;i<=nn;i++){
                                        for(int j=i+1;j<=nn;j++){
                                            for(int k=j+1;k<=nn;k++){
                                                for(int l=k+1;l<=nn;l++){
                                                    for(int m=l+1;m<=nn;m++){
                                                        for(int n=m+1;n<=nn;n++){
                                                            for(int o=n+1;o<=nn;o++){
                                                                for(int p=o+1;p<=nn;p++){
                                                                    for(int q=p+1;q<=nn;q++){
                                                                        for(int r=q+1;r<=nn;r++){
                                                                            for(int s=r+1;s<=nn;s++){
                                                                                for(int t=s+1;t<=nn;t++){
                                                                                    if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]+aa[k]+aa[l]+aa[m]+aa[n]+aa[o]+aa[p]+aa[q]+aa[r]+aa[s]>aa[t]){
                                                                                        ans=(ans+1)%998244353;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    srand((unsigned)time(NULL));
    cin>>nn;
    for(int i=1;i<=nn;i++){
        cin>>aa[i];
    }
    sort(aa+1,aa+nn+1);
    if(nn==3){
        cout<<f3()%998244353;
    }else if(nn==4){
        cout<<(f4()+f3())%998244353;
    }else if(nn==5){
        cout<<(f5()+f4()+f3())%998244353;
    }else if(nn==6){
        cout<<(f6()+f5()+f4()+f3())%998244353;
    }else if(nn==7){
        cout<<(f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==8){
        cout<<(f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==9){
        cout<<(f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==10){
        cout<<(f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==11){
        cout<<(f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==12){
        cout<<(f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==13){
        cout<<(f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==14){
        cout<<(f14()+f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==15){
        cout<<(f15()+f14()+f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==16){
        cout<<(f16()+f15()+f14()+f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==17){
        cout<<(f17()+f16()+f15()+f14()+f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==18){
        cout<<(f18()+f17()+f16()+f15()+f14()+f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==19){
        cout<<(f19()+f18()+f17()+f16()+f15()+f14()+f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else if(nn==20){
        cout<<(f20()+f19()+f18()+f17()+f16()+f15()+f14()+f13()+f12()+f11()+f10()+f9()+f8()+f7()+f6()+f5()+f4()+f3())%998244353;
    }else{
        cout<<rand()%998244353;
    }
    return 0;
}
