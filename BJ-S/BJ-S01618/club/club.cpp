/*
Ren5Jie4Di4Ling5%
*/
#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int s[10005][5];
int acsum=0;
int maxsum=-1;
void dfs(int f,int o,int t,int h){
    if(f==0){
        maxsum=max(maxsum,acsum);
        return;
    }
    for(int i=1;i<=3;i++){
        if(o==n/2&&i==1){
            continue;
        }
        if(t==n/2&&i==2){
            continue;
        }
        if(h==n/2&&i==3){
            continue;
        }
        if(i==1){
            acsum+=s[f][i];
            dfs(f-1,o+1,t,h);
            acsum-=s[f][i];
        }
        if(i==2){
            acsum+=s[f][i];
            dfs(f-1,o,t+1,h);
            acsum-=s[f][i];
        }
        if(i==3){
            acsum+=s[f][i];
            dfs(f-1,o,t,h+1);
            acsum-=s[f][i];
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int is23zero=1;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i][1]>>s[i][2]>>s[i][3];
            if(s[i][2]!=0||s[i][3]!=0){
                is23zero=0;
            }
        }
        if(is23zero==1){
            int ans[10005]={};
            for(int i=0;i<n;i++){
                ans[i]=s[i][1];
            }
            sort(ans,ans+n);
            int sum=0;
            for(int i=n-1;i>=n/2;i--){
                sum+=ans[i];
            }
            cout<<sum<<endl;
        }else{
            if(n==2){
                int option1=s[0][1]+s[1][2];
                int option2=s[0][1]+s[1][3];
                int option3=s[0][2]+s[1][3];
                int option4=s[0][2]+s[1][1];
                int option5=s[0][3]+s[1][2];
                int option6=s[0][3]+s[1][1];
                int MAX1=max(option1,option2);
                int MAX2=max(option3,option4);
                int MAX3=max(option5,option6);
                cout<<max(max(MAX1,MAX2),MAX3)<<endl;
            }else if(n==4){
                int sum=0;
                int q1,q2,q3,q4;
                q1=q2=q3=q4=0;
                for(int i=1;i<=3;i++){
                    for(int j=1;j<=3;j++){
                        for(int k=1;k<=3;k++){
                            for(int l=1;l<=3;l++){
                                if(i==1&&j==1&&k==1){
                                    continue;
                                }
                                if(i==1&&j==1&&l==1){
                                    continue;
                                }
                                if(i==1&&k==1&&l==1){
                                    continue;
                                }
                                if(j==1&&k==1&&l==1){
                                    continue;
                                }

                                if(i==2&&j==2&&k==2){
                                    continue;
                                }
                                if(i==2&&j==2&&l==2){
                                    continue;
                                }
                                if(i==2&&k==2&&l==2){
                                    continue;
                                }
                                if(j==2&&k==2&&l==2){
                                    continue;
                                }

                                if(i==3&&j==3&&k==3){
                                    continue;
                                }
                                if(i==3&&j==3&&l==3){
                                    continue;
                                }
                                if(i==3&&k==3&&l==3){
                                    continue;
                                }
                                if(j==3&&k==3&&l==3){
                                    continue;
                                }
                                if(sum<s[0][i]+s[1][j]+s[2][k]+s[3][l]){
                                    sum=s[0][i]+s[1][j]+s[2][k]+s[3][l];
                                }
                            }
                        }
                    }
                }
                cout<<sum<<endl;
            }else{
                acsum=0;
                maxsum=-1;
                dfs(n,0,0,0);
                cout<<maxsum<<endl;
            }
        }
    }

    return 0;
}
