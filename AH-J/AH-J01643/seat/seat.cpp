#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[111],num,temp,c=0,r=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    cnt=n*m;
    for(long long i=1;i<=cnt;i++)scanf("%d",&a[i]);
    temp=a[1];
    sort(a+1,a+1+cnt,cmp);
    for(long long i=1;i<=cnt;i++){
        if(a[i]==temp){
            num=i;
            break;
        }
    }
    if(num%n==0){
        c=num/n;
        if(c%2==0)r=1;
        if(c%2==1)r=n;
    }
    if(num%n>0){
        c=num/n+1;
        if(c%2==1)r=num%n;
        if(c%2==0)r=n-num%n+1;
    }
    printf("%d %d",c,r);
    return 0;
}
