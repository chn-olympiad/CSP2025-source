#include<bits/stdc++.h>
using namespace std;
int N,A[5005];
long long ans;
long long f3(){
    long long sum=0;
    for(int a=1;a<=N-2;a++){
        for(int b=a+1;b<=N-1;b++){
            for(int c=b+1;c<=N;c++){
                if(A[a]+A[b]>A[c]) sum++;
            }
        }
    }
    return sum;
}
long long f4(){
    long long sum=0;
    for(int a=1;a<=N-3;a++){
        for(int b=a+1;b<=N-2;b++){
            for(int c=b+1;c<=N-1;c++){
                for(int d=c+1;d<=N;d++){
                    if(A[a]+A[b]+A[c]>A[d]) sum++;
                }
            }
        }
    }
    return sum;
}
long long f5(){
    long long sum=0;
    for(int a=1;a<=N-4;a++){
        for(int b=a+1;b<=N-3;b++){
            for(int c=b+1;c<=N-2;c++){
                for(int d=c+1;d<=N-1;d++){
                    for(int e=d+1;e<=N;e++){
                        if(A[a]+A[b]+A[c]+A[d]>A[e]) sum++;
                    }
                }
            }
        }
    }
    return sum;
}
long long f6(){
    long long sum=0;
    for(int a=1;a<=N-5;a++){
        for(int b=a+1;b<=N-4;b++){
            for(int c=b+1;c<=N-2;c++){
                for(int d=c+1;d<=N-2;d++){
                    for(int e=d+1;e<=N-1;e++){
                        for(int f=e+1;f<=N;f++){
                            if(A[a]+A[b]+A[c]+A[d]+A[e]>A[f]) sum++;
                        }
                    }
                }
            }
        }
    }
    return sum;
}
long long f7(){
    long long sum=0;
    for(int a=1;a<=N-6;a++){
        for(int b=a+1;b<=N-5;b++){
            for(int c=b+1;c<=N-4;c++){
                for(int d=c+1;d<=N-3;d++){
                    for(int e=d+1;e<=N-2;e++){
                        for(int f=e+1;f<=N-1;f++){
                            for(int g=f+1;g<=N;g++){
                            if(A[a]+A[b]+A[c]+A[d]+A[e]+A[f]>A[g]) sum++;
                            }
                        }
                    }
                }
            }
        }
    }
    return sum;
}
long long f8(){
    long long sum=0;
    for(int a=1;a<=N-7;a++){
        for(int b=a+1;b<=N-6;b++){
            for(int c=b+1;c<=N-5;c++){
                for(int d=c+1;d<=N-4;d++){
                    for(int e=d+1;e<=N-3;e++){
                        for(int f=e+1;f<=N-2;f++){
                            for(int g=f+1;g<=N-1;g++){
                                for(int h=g+1;h<=N;h++){
                                    if(A[a]+A[b]+A[c]+A[d]+A[e]+A[f]+A[g]>A[h]) sum++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return sum;
}
long long f9(){
    long long sum=0;
    for(int a=1;a<=N-8;a++){
        for(int b=a+1;b<=N-7;b++){
            for(int c=b+1;c<=N-6;c++){
                for(int d=c+1;d<=N-5;d++){
                    for(int e=d+1;e<=N-4;e++){
                        for(int f=e+1;f<=N-3;f++){
                            for(int g=f+1;g<=N-2;g++){
                                for(int h=g+1;h<=N-1;h++){
                                    for(int i=h+1;i<=N;i++){
                                        if(A[a]+A[b]+A[c]+A[d]+A[e]+A[f]+A[g]+A[h]>A[i]) sum++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return sum;
}
long long f10(){
    long long sum=0;
    for(int a=1;a<=N-9;a++){
        for(int b=a+1;b<=N-8;b++){
            for(int c=b+1;c<=N-7;c++){
                for(int d=c+1;d<=N-6;d++){
                    for(int e=d+1;e<=N-5;e++){
                        for(int f=e+1;f<=N-4;f++){
                            for(int g=f+1;g<=N-3;g++){
                                for(int h=g+1;h<=N-2;h++){
                                    for(int i=h+1;i<=N-1;i++){
                                        for(int j=i+1;j<=N-1;j++){
                                            if(A[a]+A[b]+A[c]+A[d]+A[e]+A[f]+A[g]+A[h]+A[i]>A[j]) sum++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    sort(A+1,A+N+1);
    if(N==3){
        ans+=f3();
        ans%=998244353;
    }
    else if(N==4){
        ans+=f3();ans%=998244353;
        ans+=f4();
        ans%=998244353;
    }
    else if(N==5){
        ans+=f3();ans%=998244353;
        ans+=f4();ans%=998244353;
        ans+=f5();
        ans%=998244353;
    }
    else if(N==6){
        ans+=f3();ans%=998244353;
        ans+=f4();ans%=998244353;
        ans+=f5();ans%=998244353;
        ans+=f6();
        ans%=998244353;
    }
    else if(N==7){
        ans+=f3();ans%=998244353;
        ans+=f4();ans%=998244353;
        ans+=f5();ans%=998244353;
        ans+=f6();ans%=998244353;
        ans+=f7();
        ans%=998244353;
    }
    else if(N==8){
        ans+=f3();ans%=998244353;
        ans+=f4();ans%=998244353;
        ans+=f5();ans%=998244353;
        ans+=f6();ans%=998244353;
        ans+=f7();ans%=998244353;
        ans+=f8();
        ans%=998244353;
    }
    else if(N==9){
        ans+=f3();ans%=998244353;ans+=f4();ans%=998244353;ans+=f5();ans%=998244353;
        ans+=f6();ans%=998244353;ans+=f7();ans%=998244353;ans+=f8();ans%=998244353;ans+=f9();
        ans%=998244353;
    }
    else if(N==10){
        ans+=f3();ans%=998244353;ans+=f4();ans%=998244353;ans+=f5();ans%=998244353;ans+=f6();ans%=998244353;
        ans+=f7();ans%=998244353;ans+=f8();ans%=998244353;ans+=f9();ans%=998244353;ans+=f10();
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
