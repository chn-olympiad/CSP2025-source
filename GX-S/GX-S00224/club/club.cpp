#include<bits/stdc++.h>
#include<cmath>
using namespace std;
void swapa(int a[],int b[]){
    for(int i=0;i<3;i++){
        swap(a[i],b[i]);
    }
}
int a[10001][3],ordera[10001][3];
int main(){
    freopen("club.in","r",stdin);
//    freopen("club.out","w",stdout);
    int t,n,mina[3]={0},minai[3]={0},sum=0,lenl[3]={0},maxa;
    cin>>t;
    for(int iq=0;iq<t;iq++){
        cin>>n;
        sum=0;
        maxa=0;
        lenl[3]={0};
        minai[3]={0};
        mina[3]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            int ina;
            for(int j=0;j<3;j++){
                if(j==0){
                    maxa=a[i][j];
                    ina=a[i][j];
                    ordera[i][0]=j;
                }else{
                    if(a[i][j]>maxa){
                        ordera[i][2]=ordera[i][1];
                        ordera[i][1]=ordera[i][0];
                        maxa=a[i][j];
                        ordera[i][0]=j;
                    }else{
                        ordera[i][j]=j;
                    }
                }
            }
            for(int j=0;j<3;j++){
                if(lenl[ordera[i][j]]==n/2){
                    if(a[i][j]>mina[j]){
                        sum-=mina[j];
                        sum+=a[i][j];
                        swapa(ordera[minai[j]],ordera[i]);
                        swapa(a[minai[j]],a[i]);
                        minai[j]=i;
                        j=-1;
                        continue;
                    }else{
                        continue;
                    }
                }
                sum+=a[i][j];
                if(a[i][j]<mina[j]){
                    mina[j]=a[i][j];
                    minai[j]=i;
                    lenl[j]+=1;
                }
                break;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
