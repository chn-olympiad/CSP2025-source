#include <iostream>

using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);


    int t;
    scanf("%d",&t);
    //printf("%d\n",t);
    for(int T=0;T<t;T++){
            long long ans=0;
        long long n;
        scanf("%lld",&n);
        //printf("%lld\n",n);

        long long a0[n],a2[n],a1[n];
        long long re=0;
        long long r=0;
        long long cob[n];
        long long p0=0,p1=0,p2=0;
        bool tf=true;

        for(int i=0;i<n;i++){
                //printf("pot:\n");
                scanf("%lld %lld %lld",&a0[i],&a1[i],&a2[i]);
                if(a0[i]==0&&a1[i]==0){
                    ans+=a2[i];
                    a0[i]=0;
                    a1[i]=0;
                    a2[i]=0;
                    p2++;
                }else if(a2[i]==0&&a1[i]==0){
                    ans+=a0[i];
                    a0[i]=0;
                    a1[i]=0;
                    a2[i]=0;
                    p0++;
                }else if(a0[i]==0&&a2[i]==0){
                    ans+=a1[i];
                    a0[i]=0;
                    a1[i]=0;
                    a2[i]=0;
                    p1++;
                }
                }
                for(int i=0;i<n;i++){
                    if(a0[i]>a1[i]&&a0[i]>a2[i]){
                        cob[i]=0;
                    }else if(a1[i]>a0[i]&&a1[i]>a2[i]){
                    cob[i]=1;
                    }else if(a2[i]>a0[i]&&a2[i]>a1[i]){
                    cob[i]=2;
                    }else{
                        cob[i]=a0[i];
                    }
                }
        do{

            if(p0==n/2){
                for(int i=0;i<n;i++){
                    a0[i]=0;
                }
            }
            if(p1==n/2){
                for(int i=0;i<n;i++){
                    a1[i]=0;
                }
            }
            if(p2==n/2){
                for(int i=0;i<n;i++){
                    a2[i]=0;
                }
            }
            for(long long i=0;i<n;i++){
                if(cob[i]==0){
                    if(r==0){
                        if(a0[i]>a0[re]){
                            r=0;
                            re=i;
                        }

                    }else if(r==1){
                        if(a0[i]>a1[re]){
                            r=0;
                            re=i;
                        }

                    }else if(r==2){
                        if(a0[i]>a2[re]){
                            r=0;
                            re=i;
                        }

                    }
                }else if(cob[i]==1){
                    if(r==0){
                        if(a1[i]>a0[re]){
                            r=1;
                            re=i;
                        }

                    }else if(r==1){
                        if(a1[i]>a1[re]){
                            r=1;
                            re=i;
                        }

                    }else if(r==2){
                        if(a1[i]>a2[re]){
                            r=1;
                            re=i;
                        }

                    }
                }else if(cob[i]==2){
                    if(r==0){
                        if(a2[i]>a0[re]){
                            r=2;
                            re=i;
                        }

                    }else if(r==1){
                        if(a2[i]>a1[re]){
                            r=2;
                            re=i;
                        }

                    }else if(r==2){
                        if(a2[i]>a2[re]){
                            r=2;
                            re=i;
                        }

                    }
                }
            }
            tf=false;
            for(int i=0;i<n;i++){
                if(a0[i]!=0){
                    tf=true;
                    break;
                }
                if(a1[i]!=0){
                    tf=true;
                    break;
                }
                if(a2[i]!=0){
                    tf=true;
                    break;
                }
            }
            if(r==0){


                        ans+=a0[re];
                        a0[re]=0;
                        a1[re]=0;
                        p0++;


                    }else if(r==1){

                        ans+=a1[re];
                        a1[re]=0;
                        p1++;




                    }else if(r==2){
                        if(p2<n/2)
                        ans+=a2[re];
                        a2[re]=0;
                        p2++;

                    }
        }while(tf);
printf("%lld",ans);

    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
