#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
for(int i=1;i<=t;i++){
    int n;
    cin>>n;
    int a[100010][4];
    int maxn[100010];
    int minn[100010];
    int meme[100010];
    int ans[4]={};
    int answer=0;
    for(int j=1;j<=n;j++){
             maxn[j]=-1;
             minn[i]=2*pow(10,4)+2;
            for(int k=1;k<=3;k++){
        cin>>a[j][k];
            maxn[j]=max(maxn[j],a[j][k]);
            minn[j]=min(minn[j],a[j][k]);
            }

         if((a[j][1]==maxn[j]&&a[j][2]==minn[j])||(a[j][1]==minn[j]&&a[j][2]==maxn[j])){
                    meme[j]=a[j][3];
                }
                  if((a[j][1]==maxn[j]&&a[j][3]==minn[j])||(a[j][1]==minn[j]&&a[j][3]==maxn[j])){
                    meme[j]=a[j][2];
                }
                  if((a[j][2]==maxn[j]&&a[j][3]==minn[j])||(a[j][2]==minn[j]&&a[j][3]==maxn[j])){
                    meme[j]=a[j][1];
                }
            }

     for(int j=1;j<=n;j++){
           for(int k=1;k<=3;k++){
  if(maxn[j]==a[j][k]){
    ans[k]++;
  }
            }

   }
    bool bo=true;
           for(int k=1;k<=3;k++){
          if(ans[k]>n/2){
          bo=false;
  }
          }
          if(bo==true){
             for(int j=1;j<=n;j++){
           answer+=maxn[j];
    cout<<answer<<endl;
    break;
          }
              }else{
                 for(int j=1;j<=n;j++){
            maxn[j]=meme[j];


    }
              }

            }



fclose(stdin);
fclose(stdout);
return 0;
}





