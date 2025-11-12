#include<bits/stdc++.h>
using namespace std;
    int n,b[5005],h,ma;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>b[i];
if(n>=3){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(b[i]+b[j]+b[k]>=2*max(b[i],max(b[j],b[k]))+1&&i!=j&&j!=k&&i!=k) h++;
            }
        }
    }
}
if(n>=4){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(b[i]+b[j]+b[k]+b[l]>=2*max(b[i],max(b[j],max(b[k],b[l])))+1&&i!=j&&j!=k&&i!=k&&i!=l&&j!=l&&k!=l) h++;
                }
            }
        }
    }
}
if(n>=5){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int m=l+1;m<n;m++){
                        if(b[i]+b[j]+b[k]+b[l]+b[m]>=2*max(b[i],max(b[j],max(b[k],max(b[l],b[m]))))+1&&i!=j&&i!=k&&i!=l&&i!=m&&j!=k&&j!=l&&j!=m&&k!=l&&k!=m&&l!=m) h++;
                    }
                }
            }
        }
    }
}
if(n>=6){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int m=l+1;m<n;m++){
                        for(int o=m+1;o<n;o++){
                            if(b[i]+b[j]+b[k]+b[l]+b[m]+b[o]>=2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[m],b[o])))))+1&&i!=j&&i!=k&&i!=l&&i!=m&&j!=k&&j!=l&&j!=m&&k!=l&&k!=m&&l!=m&&i!=o&&j!=o&&k!=o&&l!=o&&m!=o) h++;
                        }
                    }
                }
            }
        }
    }
}
if(n>=7){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int m=l+1;m<n;m++){
                        for(int o=m+1;o<n;o++){
                            for(int p=o+1;p<n;p++){
                                if(b[i]+b[j]+b[k]+b[l]+b[m]+b[o]+b[p]>=2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[m],max(b[o],b[p]))))))+1&&i!=j&&i!=k&&i!=l&&i!=m&&j!=k&&j!=l&&j!=m&&k!=l&&k!=m&&l!=m&&i!=o&&j!=o&&k!=o&&l!=o&&m!=o&&i!=p&&j!=p&&k!=p&&l!=p&&m!=p&&o!=p) h++;
                            }
                        }
                    }
                }
            }
        }
    }
}
if(n>=8){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int m=l+1;m<n;m++){
                        for(int o=m+1;o<n;o++){
                            for(int p=o+1;p<n;p++){
                               for(int q=p+1;q<n;q++){
                                   if(b[i]+b[j]+b[k]+b[l]+b[m]+b[o]+b[p]+b[q]>=2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[m],max(b[o],max(b[p],b[q])))))))+1&&i!=j&&i!=k&&i!=l&&i!=m&&j!=k&&j!=l&&j!=m&&k!=l&&k!=m&&l!=m&&i!=o&&j!=o&&k!=o&&l!=o&&m!=o&&i!=p&&j!=p&&k!=p&&l!=p&&m!=p&&o!=p&&i!=q&&j!=q&&k!=q&&l!=q&&m!=q&&o!=q&&p!=q) h++;
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
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int m=l+1;m<n;m++){
                        for(int o=m+1;o<n;o++){
                            for(int p=o+1;p<n;p++){
                               for(int q=p+1;q<n;q++){
                                   for(int r=q+1;r<n;r++){
                                       if(b[i]+b[j]+b[k]+b[l]+b[m]+b[o]+b[p]+b[q]+b[r]>=2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[m],max(b[o],max(b[p],max(b[q],b[r]))))))))+1&&i!=j&&i!=k&&i!=l&&i!=m&&j!=k&&j!=l&&j!=m&&k!=l&&k!=m&&l!=m&&i!=o&&j!=o&&k!=o&&l!=o&&m!=o&&i!=p&&j!=p&&k!=p&&l!=p&&m!=p&&o!=p&&i!=q&&j!=q&&k!=q&&l!=q&&m!=q&&o!=q&&p!=q&&i!=r&&j!=r&&k!=r&&l!=r&&m!=r&&o!=r&&p!=r&&q!=r) h++;
                                   }
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
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    for(int m=l+1;m<n;m++){
                        for(int o=m+1;o<n;o++){
                            for(int p=o+1;p<n;p++){
                               for(int q=p+1;q<n;q++){
                                   for(int r=q+1;r<n;r++){
                                       for(int s=r+1;s<n;s++){
                                            if(b[i]+b[j]+b[k]+b[l]+b[m]+b[o]+b[p]+b[q]+b[r]+b[s]>=2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[m],max(b[o],max(b[p],max(b[q],max(b[r],b[s])))))))))+1&&i!=j&&i!=k&&i!=l&&i!=m&&j!=k&&j!=l&&j!=m&&k!=l&&k!=m&&l!=m&&i!=o&&j!=o&&k!=o&&l!=o&&m!=o&&i!=p&&j!=p&&k!=p&&l!=p&&m!=p&&o!=p&&i!=q&&j!=q&&k!=q&&l!=q&&m!=q&&o!=q&&p!=q&&i!=r&&j!=r&&k!=r&&l!=r&&m!=r&&o!=r&&p!=r&&q!=r&&i!=s&&j!=s&&k!=s&&l!=s&&m!=s&&o!=s&&p!=s&&q!=s&&r!=s) h++;
                                       }
                                   }
                               }
                            }
                        }
                    }
                }
            }
        }
    }
}
    h%=998244353;
    cout<<h;
}
