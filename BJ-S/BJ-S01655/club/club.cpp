#include<bits/stdc++.h>
using namespace std;
int a[100006][3];
int b[100006];
bool my_cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin >> t;
    while(t--){
        int n,ma=0,f=1;scanf("%d",&n);
        for(int i = 1;i <= n;++i){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            if(a[i][1]||a[i][2]){f=0;}
            b[i]=a[i][0];
        }
        if(n==2){
            ma=max(ma,a[1][0]+a[2][1]);ma=max(ma,a[1][0]+a[2][2]);
            ma=max(ma,a[1][1]+a[2][0]);ma=max(ma,a[1][1]+a[2][2]);
            ma=max(ma,a[1][2]+a[2][0]);ma=max(ma,a[1][2]+a[2][1]);
            cout << ma << '\n';
        }else if(n==4){
            for(int i1 = 0;i1 < 3;++i1){
                for(int i2 = 0;i2 < 3;++i2){
                    for(int i3 = 0;i3 < 3;++i3){
                        for(int i4 = 0;i4 < 3;++i4){
                            int ok[3]={0,0,0};
                            ++ok[i1];++ok[i2];
                            ++ok[i3];++ok[i4];
                            if((ok[0]<=2)&&(ok[1]<=2)&&(ok[2]<=2)){
                                ma=max(ma,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
                            }
                        }
                    }
                }
            }
            cout << ma << '\n';
        }else if(f){
            sort(b+1,b+n+1,my_cmp);
            long long sum = 0;
            for(int i = 1;i <= (n/2);++i){sum += b[i];}
            cout << sum << '\n';
        }else if(n==10){
            for(int i1 = 0;i1 < 3;++i1){
            for(int i2 = 0;i2 < 3;++i2){
            for(int i3 = 0;i3 < 3;++i3){
            for(int i4 = 0;i4 < 3;++i4){
            for(int i5 = 0;i5 < 3;++i5){
            for(int i6 = 0;i6 < 3;++i6){
            for(int i7 = 0;i7 < 3;++i7){
            for(int i8 = 0;i8 < 3;++i8){
            for(int i9 = 0;i9 < 3;++i9){
            for(int i10 = 0;i10 < 3;++i10){
                int ok[3]={0,0,0};
                ++ok[i1];++ok[i2];
                ++ok[i3];++ok[i4];
                ++ok[i5];++ok[i6];
                ++ok[i7];++ok[i8];
                ++ok[i9];++ok[i10];
                if((ok[0]<=5)&&(ok[1]<=5)&&(ok[2]<=5)){
ma=max(ma,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10]);
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
            cout << ma << '\n';
        }else{
        }
    }
    return 0;
}
