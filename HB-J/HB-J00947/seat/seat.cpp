#include<bits/stdc++.h>
using namespace std;
int saet[1203][1003];
int m_saet[1203][3434];
int xh,xl;
int grade[10022],num;
bool cmp(int x,int y){
return  x > y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n;
scanf("%d %d",&n,&m);
int p=n*m;
for(int i=1;i<=p;i++){
    scanf("%d",&grade);
}
printf("%d %d",&m,&n);
    return 0;
}
