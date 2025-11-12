#include<bits/stdc++.h>
using namespace std;
int a[5001];
long long sum=0;
const long long N=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(n<=3){
        if(n<3){
            printf("0");
            return 0;
        }
        if(a[1]+a[2]>a[3]) printf("1");
        else printf("0");
        return 0;
    }
    if(n<=10){
        int cnt=0;
        for(int i=n;i>=3;i--){
            for(int j=i-1;j>=2;j--){
                for(int k=j-1;k>=1;k--){
                    if(a[j]+a[k]<=a[i]){
                        break;
                    }
                    else cnt++;
                }
            }
        }
        for(int i=n;i>=4;i--){
            for(int j=i-1;j>=3;j--){
                for(int k=j-1;k>=2;k--){
                    for(int l=k-1;l>=1;l--){
                        if(a[l]+a[k]+a[j]<=a[i]) break;
                        else cnt++;
                    }
                }
            }
        }
        for(int i=n;i>=5;i--){
            for(int j=i-1;j>=4;j--){
                for(int k=j-1;k>=3;k--){
                    for(int l=k-1;l>=2;l--){
                        for(int o=l-1;o>=1;o--){
                            if(a[l]+a[k]+a[j]+a[o]<=a[i]) break;
                            else cnt++;
                        }
                    }
                }
            }
        }
        for(int i=n;i>=6;i--){
            for(int j=i-1;j>=5;j--){
                for(int k=j-1;k>=4;k--){
                    for(int l=k-1;l>=3;l--){
                        for(int o=l-1;o>=2;o--){
                            for(int p=o-1;p>=1;p--){
                                if(a[l]+a[k]+a[j]+a[o]+a[p]<=a[i]) break;
                                else cnt++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=n;i>=7;i--){
            for(int j=i-1;j>=6;j--){
                for(int k=j-1;k>=5;k--){
                    for(int l=k-1;l>=4;l--){
                        for(int o=l-1;o>=3;o--){
                            for(int p=o-1;p>=2;p--){
                                for(int q=p-1;q>=1;q--){
                                    if(a[l]+a[k]+a[j]+a[o]+a[p]+a[q]<=a[i]) break;
                                    else cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=n;i>=8;i--){
            for(int j=i-1;j>=7;j--){
                for(int k=j-1;k>=6;k--){
                    for(int l=k-1;l>=5;l--){
                        for(int o=l-1;o>=4;o--){
                            for(int p=o-1;p>=3;p--){
                                for(int q=p-1;q>=2;q--){
                                    for(int r=q-1;r>=1;r--){
                                        if(a[l]+a[k]+a[j]+a[o]+a[p]+a[q]+a[r]<=a[i]) break;
                                        else cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=n;i>=9;i--){
            for(int j=i-1;j>=8;j--){
                for(int k=j-1;k>=7;k--){
                    for(int l=k-1;l>=6;l--){
                        for(int o=l-1;o>=5;o--){
                            for(int p=o-1;p>=4;p--){
                                for(int q=p-1;q>=3;q--){
                                    for(int r=q-1;r>=2;r--){
                                        for(int s=r-1;s>=1;s--){
                                            if(a[l]+a[k]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]<=a[i]) break;
                                            else cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(sum-a[n]>a[n]) cnt++;
        printf("%d",cnt);
        return 0;
    }
    if(a[n]<=1){
        for(int i=3;i<=n;i++){
            long long x=1;
            for(int j=n;j>=n-i+1;j--){
                x=(x*j)%N;
            }
            for(int j=i;j>=1;j--){
                x=(x/j)%N;
            }
            sum=(sum+x)%N;
        }
        printf("%lld",sum);
        return 0;
    }
    long long sum=0;
    for(int i=3;i<=n;i++){
        long long x=1;
        for(int j=n;j>=n-i+1;j--){
            x=(x*j)%N;
        }
        for(int j=i;j>=1;j--){
            x=(x/j)%N;
        }
        sum=(sum+x)%N;
    }
    printf("%lld",sum);
    return 0;
}
