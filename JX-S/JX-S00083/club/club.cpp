#include <iostream>
using namespace std;

int n;
int s1=0,s2=0,s3=0;
int num=0;

struct clu{
    int e1,e2,e3;
    bool in;
}we[100005];



void f(){
    int e=n/2;
    if(s1<=e&&s2<=e&&s3<=e){
        cout<< num;
        return;
    }

}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>> t;
    while(t>0){
        t--;
        cin>> n;


        int x1[3*n+5]={},x2[3*n+5]={},x3[3*n+5]={};
        int k=1;
        for(int i=1;i<=n;i++){
            cin>> we[i].e1 >> we[i].e2 >> we[i].e3;
            x1[k]=we[i].e1;
            x1[k+1]=we[i].e2;
            x1[k+2]=we[i].e3;
            x2[k]=x2[k+1]=x2[k+2]=i;
            x3[k]=1,x3[k+1]=2,x3[k+2]=3;
            k+=3;
        }
        /*
        for(int i=1;i<=3*n;i++){
            for(int j=i+2;j<=3*n;j++){
                if(x1[i]<x1[j]){
                    int a=x1[i],b=x2[i],c=x3[i];
                    x1[i]=x1[j];
                    x1[j]=a;
                    x2[i]=x2[j];
                    x2[j]=b;
                    x3[i]=x3[j];
                    x3[j]=c;
                }
            }
        }
        */
        for(int i=1;i<=n;i++){
            if(we[i].e1>we[i].e2){
                if(we[i].e3>we[i].e1){
                    s3++;
                    num+=we[i].e3;
                } else{
                    s1++;
                    num+=we[i].e1;
                }
            } else{
                if(we[i].e3>we[i].e2){
                    s3++;
                    num+=we[i].e3;
                } else{
                    s2++;
                    num+=we[i].e2;
                }
            }
        }
        f();
        s1=s2=s3=0;
        num=0;
        cout<< endl;
    }

    fclose(stdin);
    fclose(stdout);


    return 0;
}
