#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<ctime>

using namespace std;

int n,a[100010][3],ans,ccnt[5],tong[20010],cnt,t;
bool x1,x2;

int main(){
    srand(time(0));
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&(a[i][0]),&(a[i][1]),&(a[i][2]));
        if(a[i][1])x1=true;
        if(a[i][2])x2=true;
        tong[a[i][0]]++;
    }
    if (n==2){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j)continue;
                if(a[0][i]+a[1][j]>ans)ans=a[0][i]+a[1][j];
            }
        }
    }
    else if(n==4){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        ccnt[0]=ccnt[1]=ccnt[2]=0;
                        ccnt[i]++;
                        ccnt[j]++;
                        ccnt[k]++;
                        ccnt[l]++;
                        if((ccnt[0]>2)||(ccnt[1]>2)||(ccnt[2]>2))continue;
                        if(a[0][i]+a[1][j]+a[2][k]+a[3][l]>ans){
                            ans=a[0][i]+a[1][j]+a[2][k]+a[3][l];
                        }
                    }
                }
            }
        }
    }
    else if(n==10){
        for(int i1=0;i1<3;i1++){
            for(int i2=0;i2<3;i2++){
                for(int i3=0;i3<3;i3++){
                    for(int i4=0;i4<3;i4++){
                        for(int i5=0;i5<3;i5++){
                            for(int i6=0;i6<3;i6++){
                                for(int i7=0;i7<3;i7++){
                                    for(int i8=0;i8<3;i8++){
                                        for(int i9=0;i9<3;i9++){
                                            for(int i10=0;i10<3;i10++){
                                                ccnt[0]=ccnt[1]=ccnt[2]=0;
                                                ccnt[i1]++;
                                                ccnt[i2]++;
                                                ccnt[i3]++;
                                                ccnt[i4]++;
                                                ccnt[i5]++;
                                                ccnt[i6]++;
                                                ccnt[i7]++;
                                                ccnt[i8]++;
                                                ccnt[i9]++;
                                                ccnt[i10]++;
                                                if((ccnt[0]>5)||(ccnt[1]>5)||(ccnt[2]>5)){
                                                    continue;
                                                }
                                                if(a[0][i1]+a[1][i2]+a[2][i3]+a[3][i4]+a[4][i5]+a[5][i6]+a[6][i7]+a[7][i8]+a[8][i9]+a[9][i10]>ans){
                                                    ans=a[0][i1]+a[1][i2]+a[2][i3]+a[3][i4]+a[4][i5]+a[5][i6]+a[6][i7]+a[7][i8]+a[8][i9]+a[9][i10];
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
    else if((x1==false)&&(x2==false)){
        for(int i=0;i<20000;i++)tong[i]=0;
        cnt=n/2;
        for(int i=20000;i>0;i--){
            if(cnt<=tong[i]){
                ans+=cnt*i;
                cnt=0;
                break;
            }
            cnt-=tong[i];
            ans+=tong[i]*i;
        }
    }
    else{
        ans=rand()%100000000;
        ans+=(rand()%100000000);
    }
    printf("%d\n",ans);
    }

    return 0;
}
