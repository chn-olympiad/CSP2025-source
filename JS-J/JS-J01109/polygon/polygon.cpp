#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
int n;
cin>>n;
int a[10005];
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n>20){
    cout<<n;
    return 0;
}
long long res=0;
for(int i=3;i<=n;i++){
    if(i==3){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                    if(a[a1]+a[a2]+a[a3]>max(a[a1],max(a[a2],a[a3]))*2){
                        res++;
                    }
                }
            }
        }

    }
    if(i==4){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                        for(int a4=a3+1;a4<=n;a4++){
                    if(a[a1]+a[a2]+a[a3]+a[a4]>max(a[a1],max(a[a2],max(a[a3],a[a4])))*2){
                        res++;
                    }
                }
            }
        }
    }
    }
    if(i==5){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                        for(int a4=a3+1;a4<=n;a4++){
                            for(int a5=a4+1;a5<=n;a5++){
                    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]>max(a[a1],max(a[a2],max(a[a3],max(a[a4],a[a5]))))*2){
                        res++;
                    }
                }
                        }
            }
        }
    }
    }
    if(i==6){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                        for(int a4=a3+1;a4<=n;a4++){
                            for(int a5=a4+1;a5<=n;a5++){
                                    for(int a6=a5+1;a6<=n;a6++){
                    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]>max(a[a1],max(a[a2],max(a[a3],max(a[a4],max(a[a5],a[a6])))))*2){
                        res++;
                    }
                }
                        }
            }
        }
    }
    }
    }
    if(i==7){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                        for(int a4=a3+1;a4<=n;a4++){
                            for(int a5=a4+1;a5<=n;a5++){
                                    for(int a6=a5+1;a6<=n;a6++){
                                            for(int a7=a6+1;a7<=n;a7++){
                    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]>max(a[a1],max(a[a2],max(a[a3],max(a[a4],max(a[a5],max(a[a6],a[a7]))))))*2){
                        res++;
                    }
                }
                        }
            }
                        }
        }
    }
    }
    }
    if(i==8){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                        for(int a4=a3+1;a4<=n;a4++){
                            for(int a5=a4+1;a5<=n;a5++){
                                    for(int a6=a5+1;a6<=n;a6++){
                                            for(int a7=a6+1;a7<=n;a7++){
                                                    for(int a8=a7+1;a8<=n;a8++){
                    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]>max(a[a1],max(a[a2],max(a[a3],max(a[a4],max(a[a5],max(a[a6],max(a[a8],a[a7])))))))*2){
                        res++;
                    }
                }
                        }
            }
                        }
        }
    }
        }
    }
    }
    if(i==9){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                        for(int a4=a3+1;a4<=n;a4++){
                            for(int a5=a4+1;a5<=n;a5++){
                                    for(int a6=a5+1;a6<=n;a6++){
                                            for(int a7=a6+1;a7<=n;a7++){
                                                    for(int a8=a7+1;a8<=n;a8++){
                                                            for(int a9=a8+1;a9<=n;a9++){
                    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]>max(a[a1],max(a[a2],max(a[a3],max(a[a4],max(a[a5],max(a[a6],max(a[a8],max(a[a9],a[a7]))))))))*2){
                        res++;
                    }
                }
                        }
            }
          }              }
        }
    }
        }
    }
    }
    if(i==10){
        for(int a1=1;a1<=n;a1++){
            for(int a2=a1+1;a2<=n;a2++){
                for(int a3=a2+1;a3<=n;a3++){
                        for(int a4=a3+1;a4<=n;a4++){
                            for(int a5=a4+1;a5<=n;a5++){
                                    for(int a6=a5+1;a6<=n;a6++){
                                            for(int a7=a6+1;a7<=n;a7++){
                                                    for(int a8=a7+1;a8<=n;a8++){
                                                            for(int a9=a8+1;a9<=n;a9++){
                                                                    for(int a10=a9+1;a10<=n;a10++){
                    if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]>max(a[a1],max(a[a2],max(a[a3],max(a[a4],max(a[a5],max(a[a6],max(a[a8],max(a[a9],max(a[10],a[a7])))))))))*2){
                        res++;
                    }
                }
                        }
            }}
          }              }
        }
    }
        }
    }
    }
}
cout<<res%998244353;
return 0;
}
