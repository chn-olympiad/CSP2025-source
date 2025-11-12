#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    FILE *fp=fopen("number.in","r+");
    FILE *fw=fopen("number.out","w+");
    int n,s=0,k=0;
    int a[5005]={0};
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fp,"%d",&a[i]);
        if(i>=2 && a[i]<k){
            s+=1;
        }
        k+=a[i];
    }
    fprintf(fw,"%d",k);
return 0;
}
