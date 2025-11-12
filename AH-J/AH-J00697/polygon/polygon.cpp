#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[5005];
const long long MOD=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==3){
        int ma=-1,sum=0;
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
            sum+=a[i];
        }
        if(sum>2*ma) cout<<1;
        else cout<<0;
    }else{
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if((a[i]+a[j]+a[k])>2*max(a[i],max(a[j],a[k]))){
                        cnt++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        if((a[i]+a[j]+a[k]+a[l])>2*max(a[i],max(a[j],max(a[k],a[l])))){
                            cnt++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int o=l+1;o<=n;o++){
                            if((a[i]+a[j]+a[k]+a[l]+a[o])>2*max(a[i],max(a[j],max(a[k],max(a[l],a[o]))))){
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int o=l+1;o<=n;o++){
                            for(int v=o+1;v<=n;v++){
                                if((a[i]+a[j]+a[k]+a[l]+a[o]+a[v])>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],a[v])))))){
                                    cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int o=l+1;o<=n;o++){
                            for(int v=o+1;v<=n;v++){
                                for(int s=v+1;s<=n;s++){
                                    if((a[i]+a[j]+a[k]+a[l]+a[o]+a[v]+a[s])>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(a[v],a[s]))))))){
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int o=l+1;o<=n;o++){
                            for(int v=o+1;v<=n;v++){
                                for(int s=v+1;s<=n;s++){
                                    for(int q=s+1;q<=n;q++){
                                        if((a[i]+a[j]+a[k]+a[l]+a[o]+a[v]+a[s]+a[q])>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(a[v],max(a[s],a[q])))))))){
                                            cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int o=l+1;o<=n;o++){
                            for(int v=o+1;v<=n;v++){
                                for(int s=v+1;s<=n;s++){
                                    for(int q=s+1;q<=n;q++){
                                        for(int y=q+1;y<=n;y++){
                                            if((a[i]+a[j]+a[k]+a[l]+a[o]+a[v]+a[s]+a[q]+a[y])>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(a[v],max(a[s],max(a[q],a[y]))))))))){
                                                cnt++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int o=l+1;o<=n;o++){
                            for(int v=o+1;v<=n;v++){
                                for(int s=v+1;s<=n;s++){
                                    for(int q=s+1;q<=n;q++){
                                        for(int y=q+1;y<=n;y++){
                                            for(int z=y+1;z<=n;z++){
                                                if((a[i]+a[j]+a[k]+a[l]+a[o]+a[v]+a[s]+a[q]+a[y]+a[z])>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[o],max(a[v],max(a[s],max(a[q],max(a[y],a[z])))))))))){
                                                    cnt++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
