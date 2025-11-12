#include<iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int s,n,m,k,ui[100],vi[100],wi[100],a[100],c[100];
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>ui[i]>>vi[i]>>wi[i];

    }
    for(int j=1;j<=k;j++){
            cin>>c[j];
        for(int q=0;q<n;q++){
            cin>>a[q];


        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(wi[j]>wi[j+1]){
                s=wi[j];
                wi[j]=wi[j+1];
                wi[j+1]=s;
            }


        }


    }
   // s=w[0]+w[1]+c[0];
   s=0;
    for(int i=0;i<k;i++){
        if(c[i]>c[i+1]){
            c[i]=c[i+1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]>a[j+1]){
                s=a[j];
                a[j]=a[j+1];
                a[j+1]=a[j];
            }
        }
    }
    s=wi[0]+wi[1]+c[0]+a[0]+a[1];
    cout<<s;
























}
