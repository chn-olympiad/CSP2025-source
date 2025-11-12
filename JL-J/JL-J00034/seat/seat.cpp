#include<bits/stdc++.h>
using namespace std;
unsigned n,m,s[3000],score;
bool cmp(unsigned a,unsigned b){
return a>b;}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
scanf("%u%u",&n,&m);
for(int i=1;i<=n*m;i++)scanf("%u",&s[i]);
score=s[1];
sort(s+1,s+n*m+1,cmp);
//for(int i=1;i<=n*m;i++)printf("%u ",s[i]);
unsigned seat[15][15],pos=1;
for(int i=1;i<=m;i++){
        if(i%2)
for(int j=1;j<=n;j++){
    seat[i][j]=s[pos++];
    if(seat[i][j]==score)return printf("%d %d",i,j);
}
else for(int j=n;j>0;j--){
    seat[i][j]=s[pos++];
    if(seat[i][j]==score)return printf("%d %d",i,j);
}
}

return 0;

}
