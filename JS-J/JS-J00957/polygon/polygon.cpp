#include<iostream>
#include<cmath>
using namespace std;
int at[]

int maxen(int a[],int size){
    int t=0,i;
    for(i=0;i<size;i++){
        t = max(t,a[i]);
    }
    return t;
}

bool ispolygons(int a[],int size){
    int s=0,i;
    for(i=0;i<size;i++){
        s += a[i];
    }
    if(s<=maxen(a,size)*2){
        return false;
    }
    return true;
}

int Deeper(int a[],int size,int up){
    int i,j,s=0;
    if(up==1){

    }
    for(i=0;i<size-up;i++){
        int ak[size-i];
        for(j=i+1;j<size;j++){
            ak[j-i-1] = a[j];
        }
        s += Deeper(ak,size-i,up-1);
    }
}

int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
