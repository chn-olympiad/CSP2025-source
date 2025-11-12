#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>T;
    while(T--){
        cin>>n;
        int a[n][3],max5=n/2,ans=0,my[n],stmy[3]={0,0,0},stmyr[n][3],f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                stmyr[i][j]=0;
            }
            my[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];

                if(my[i]<a[i][j]){
                    my[i]=a[i][j];
                    f=j;
                }
            }
            stmy[f]++;
            stmyr[i][f]=1;
        }
        bool flag=true;
        for(int i=0;i<3;i++){
            if(stmy[i]>max5){
                flag=false;
                f=i;
            }
        }
        if(flag){
           for(int i=0;i<n;i++){
                ans+=my[i];
            }
            cout<<ans<<endl;
        }
        else{
            while(stmy[f]>max5){
                int min1=20000,max2=-1,fi=0,j1=0;
            for(int i=0;i<n;i++){
                if(stmyr[i][f]==1 && a[i][f]<min1){
                    min1=a[i][f];
                    fi=i;
                }
            }
            a[fi][f]=-10;
            stmyr[fi][f]=0;
            for(int j=0;j<3;j++){
                if(a[fi][j]>max2){
                    max2=a[fi][j];
                    j1=j;
                }
            }
            my[fi]=max2;
            stmyr[fi][j1]=1;
            stmy[f]--;
            stmy[j1]++;
            }
            for(int i=0;i<n;i++){
                ans+=my[i];
            }
            cout<<ans<<endl;
        }
}
    fclose(stdin);
    fclose(stdout);
return 0;
}
