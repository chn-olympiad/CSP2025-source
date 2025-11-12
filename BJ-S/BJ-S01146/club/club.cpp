#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n=0,sum=0;
        cin>>n;
        if(n==2){
            int ans1=0,ans2=0,ans3=0;
            int a[2][3];
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){
                    cin>>a[i][j];
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==j){
                        continue;
                    }
                    else{
                        sum=max(sum,a[0][i]+a[1][j]);
                    }
                }
            }
            cout<<sum<<endl;
        }
        else if(n==4){
            int ans1=0,ans2=0,ans3=0;
            int a[n][3];
            for(int i=0;i<n;i++){
                for(int j=0;j<3;j++){
                    cin>>a[i][j];
                }
            }
            for(int i=0;i<3;i++){
                ans1=0;
                ans2=0;
                ans3=0;
                if(i==0){
                    ans1=1;
                }
                if(i==1){
                    ans2=1;
                }
                if(i==2){
                    ans3=1;
                }
                if(ans1>n/2 || ans2>n/2 || ans3>n/2){
                    continue;
                }
                for(int j=0;j<3;j++){
                    if(j==0){
                        ans1++;
                    }
                    if(j==1){
                        ans2++;
                    }
                    if(j==2){
                        ans3++;
                    }
                    if(ans1>n/2 || ans2>n/2 || ans3>n/2){
                        if(j==0){
                            ans1--;
                        }
                        if(j==1){
                            ans2--;
                        }
                        if(j==2){
                            ans3--;
                            if(i==0){
                                ans1--;
                            }
                            if(i==1){
                                ans2--;
                            }
                            if(i==2){
                                ans3--;
                            }
                        }
                        continue;
                    }
                    for(int k=0;k<3;k++){
                        if(k==0){
                            ans1++;
                        }
                        if(k==1){
                            ans2++;
                        }
                        if(k==2){
                            ans3++;
                        }
                        if(ans1>n/2 || ans2>n/2 || ans3>n/2){
                            if(k==0){
                                ans1--;
                            }
                            if(k==1){
                                ans2--;
                            }
                            if(k==2){
                                ans3--;
                                if(j==0){
                                    ans1--;
                                }
                                if(j==1){
                                    ans2--;
                                }
                                if(j==2){
                                    ans3--;
                                }
                            }
                            continue;
                        }
                        for(int l=0;l<3;l++){
                            if(l==0){
                                ans1++;
                            }
                            if(l==1){
                                ans2++;
                            }
                            if(l==2){
                                ans3++;
                            }
                            if(ans1>n/2 || ans2>n/2 || ans3>n/2){
                                if(l==0){
                                    ans1--;
                                }
                                if(l==1){
                                    ans2--;
                                }
                                if(l==2){
                                    ans3--;
                                }
                                continue;
                            }
                            sum=max(sum,a[0][i]+a[1][j]+a[2][k]+a[3][l]);
                            if(l==0){
                                ans1--;
                            }
                            if(l==1){
                                ans2--;
                            }
                            if(l==2){
                                ans3--;
                                if(k==0){
                                    ans1--;
                                }
                                if(k==1){
                                    ans2--;
                                }
                                if(k==2){
                                    ans3--;
                                    if(j==0){
                                        ans1--;
                                    }
                                    if(j==1){
                                        ans2--;
                                    }
                                    if(j==2){
                                        ans3--;
                                        if(i==0){
                                            ans1--;
                                        }
                                        if(i==1){
                                            ans2--;
                                        }
                                        if(i==2){
                                            ans3--;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout<<sum<<endl;
        }

    }
    return 0;
}