#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int a[100005][5];
        int first[100005];
        int second[100005];
        int third[100005];
        int n,sum1=0,sum2=0,sum3=0,ans=-1,cnt=1;
        bool tag=false;
        cin>>n;
        int x=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            first[i]=a[i][1];
            second[i]=a[i][2];
            third[i]=a[i][3];
        }
        for(int i=1;i<=n;i++){
            sum1+=first[i];
            sum2+=second[i];
            sum3+=third[i];
        }
        if(sum2==0&&sum3==0){
            sort(first+1,first+1+n);
            for(int i=1;i<=x;i++){
                sum1-=first[i];
            }
            cout<<sum1<<endl;
        }
        if(n==2){
            cout<<max(max(max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),a[1][2]+a[2][1]),a[1][2]+a[2][3]),a[1][3]+a[2][1]),a[1][3]+a[2][2]);
        }
        if(n==4){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        for(int h=1;h<=3;h++){
                            if(i==j||i==k||i==h){
                                cnt++;
                            }
                            if(j==k||j==h){
                                cnt++;
                            }
                            if(k==h){
                                cnt++;
                            }
                            if(cnt>2){
                                cnt=1;
                                continue;
                            }else{
                                cnt=1;

                                ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][h]);
                            }
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
        if(n==10){
            for(int k=1;k<=3;k++){
                for(int b=1;b<=3;b++){
                    for(int c=1;c<=3;c++){
                        for(int d=1;d<=3;d++){
                            for(int e=1;e<=3;e++){
                                for(int f=1;f<=3;f++){
                                    for(int g=1;g<=3;g++){
                                        for(int h=1;h<=3;h++){
                                            for(int i=1;i<=3;i++){
                                                for(int j=1;j<=3;j++){
                                                    if(k==b||k==c||k==d||k==e||k==f||k==g||k==h||k==i||k==j){
                                                        cnt++;
                                                    }
                                                    if(b==c||b==d||b==e||b==f||b==g||b==h||b==i||b==j){
                                                        cnt++;
                                                    }
                                                    if(c==d||c==e||c==f||c==g||c==h||c==i||c==j){
                                                        cnt++;
                                                    }
                                                    if(d==e||d==f||d==g||d==h||d==i||d==j){
                                                        cnt++;
                                                    }
                                                    if(e==f||e==g||e==h||e==i||e==j){
                                                        cnt++;
                                                    }
                                                    if(f==g||f==h||f==i||f==j){
                                                        cnt++;
                                                    }
                                                    if(g==h||g==i||g==j){
                                                        cnt++;
                                                    }
                                                    if(h==i||h==j){
                                                        cnt++;
                                                    }
                                                    if(i==j){
                                                        cnt++;
                                                    }
                                                    if(cnt>5){
                                                        cnt=1;
                                                        continue;
                                                    }else{
                                                        cnt=1;
                                                        ans=max(ans,a[1][k]+a[2][b]+a[3][c]+a[4][d]+a[5][e]+a[6][f]+a[7][g]+a[8][h]+a[9][i]+a[10][j]);
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
            cout<<ans<<endl;
        }

    }

    return 0;
}
