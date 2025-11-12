#include<bits/stdc++.h>
using namespace std;
int n;
int sum;
int const N=1e4+10;
long long ans;
int a[N];
long long dp[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        cout<<dp[3];
        return 0;
    }
    if(n==4){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    if(a[k]<a[i]+a[j]+a[p])dp[4]++;
                }
                }
            }
        }
        cout<<dp[3]+dp[4];
        return 0;
    }
    if(n==5){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    if(a[k]<a[i]+a[j]+a[p])dp[4]++;
                }
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    for(int f=k+1;f<=n;f++){
                        if(a[f]<a[i]+a[j]+a[k]+a[p])dp[5]++;
                    }
                }
                }
            }
        }
        cout<<dp[3]+dp[4]+dp[5];
        return 0;
    }
    if(n==6){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    if(a[k]<a[i]+a[j]+a[p])dp[4]++;
                }
                }
            }
        }
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        if(a[f]<a[i]+a[j]+a[k]+a[p])dp[5]++;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                        if(a[x]<a[i]+a[j]+a[k]+a[p]+a[f])dp[6]++;
        cout<<dp[3]+dp[4]+dp[5]+dp[6];
        return 0;
    }
     if(n==7){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    if(a[k]<a[i]+a[j]+a[p])dp[4]++;
                }
                }
            }
        }
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        if(a[f]<a[i]+a[j]+a[k]+a[p])dp[5]++;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                        if(a[x]<a[i]+a[j]+a[k]+a[p]+a[f])dp[6]++;
                        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                        if(a[y]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x])dp[7]++;
        cout<<dp[3]+dp[4]+dp[5]+dp[6]+dp[7];
        return 0;
    }
    if(n==8){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    if(a[k]<a[i]+a[j]+a[p])dp[4]++;
                }
                }
            }
        }
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        if(a[f]<a[i]+a[j]+a[k]+a[p])dp[5]++;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                        if(a[x]<a[i]+a[j]+a[k]+a[p]+a[f])dp[6]++;
                        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                        if(a[y]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x])dp[7]++;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                for(int z=y+1;z<=n;z++)
                        if(a[z]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x]+a[y])dp[8]++;
        cout<<dp[3]+dp[4]+dp[5]+dp[6]+dp[7]+dp[8];
        return 0;
    }
    if(n==9){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    if(a[k]<a[i]+a[j]+a[p])dp[4]++;
                }
                }
            }
        }
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        if(a[f]<a[i]+a[j]+a[k]+a[p])dp[5]++;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                        if(a[x]<a[i]+a[j]+a[k]+a[p]+a[f])dp[6]++;
                        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                        if(a[y]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x])dp[7]++;
                        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                for(int z=y+1;z<=n;z++)
                        if(a[z]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x]+a[y])dp[8]++;
                        for(int i=1;i<=n;i++)
                        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                for(int z=y+1;z<=n;z++)
                                    for(int w=z+1;z<=n;z++)
                        if(a[w]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x]+a[y]+a[z])dp[9]++;
        cout<<dp[3]+dp[4]+dp[5]+dp[6]+dp[7]+dp[8]+dp[9];
        return 0;
    }
    if(n==10){
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                if(a[p]<a[i]+a[j])dp[3]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                for(int k=p+1;k<=n;k++){
                    if(a[k]<a[i]+a[j]+a[p])dp[4]++;
                }
                }
            }
        }
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        if(a[f]<a[i]+a[j]+a[k]+a[p])dp[5]++;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                        if(a[x]<a[i]+a[j]+a[k]+a[p]+a[f])dp[6]++;
                        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                        if(a[y]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x])dp[7]++;
                        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                for(int z=y+1;z<=n;z++)
                        if(a[z]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x]+a[y])dp[8]++;
                        for(int i=1;i<=n;i++)
                        for(int j=i+1;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                for(int z=y+1;z<=n;z++)
                                    for(int w=z+1;z<=n;z++)
                        if(a[w]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x]+a[y]+a[z])dp[9]++;
                        for(int i=1;i<=n;i++)
                            for(int j=1+i;j<=n;j++)
            for(int p=j+1;p<=n;p++)
                for(int k=p+1;k<=n;k++)
                    for(int f=k+1;f<=n;f++)
                        for(int x=f+1;x<=n;x++)
                            for(int y=x+1;y<=n;y++)
                                for(int z=y+1;z<=n;z++)
                                    for(int w=z+1;z<=n;z++)
                                        for(int o=w+1;o<=n;o++)
                        if(a[o]<a[i]+a[j]+a[k]+a[p]+a[f]+a[x]+a[y]+a[z]+a[w])dp[10]++;
        cout<<dp[3]+dp[4]+dp[5]+dp[6]+dp[7]+dp[8]+dp[9]+dp[10];
        return 0;
    }
    return 0;
}
