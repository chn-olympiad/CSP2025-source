#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,jn,d;
    scanf("%d%d",&n,&m);
    c=n*m;
    int a[c],b[c];
    for (int i=0;i<c;i++){
        scanf("%d",&a[i]);
        b[i]=i+1;}
    for (int i=1;i<=c;i++){
        bool f;
        for (int j=1;j<c;j++){
        if(a[j]>a[j-1]){
            swap(a[j],a[j-1]);
            swap(b[j],b[j-1]);
            f=0;}}
    if (f){
        break;}}
    for (int j=0;j<c;j++){
        if (b[j]==1){
            jn=j;}}
    jn+=1;
    if (jn%m==0){
        d=jn/m;}
    else{
        d=jn/m+1;}
    printf("%d",d);
    cout<<' ';
    if (d%2==0){
        if (jn%m==0){
            cout<<1;}
        else{
            printf("%d",m-jn%m+1);}}
    else{
        if (jn%m==0){
            printf("%d",m);}
        else{
            printf("%d",jn%m);}
    }}
