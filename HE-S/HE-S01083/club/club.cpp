#include <bits/stdc++.h>
using namespace std;
int main(){
/*freopen("club.in","r",stdin);
freopen("club.out","w",stdout);*/
int a;
cin>>a;
for(int l=0;l<a;l++){
int n,c1=0,c2=0,c3=0,h=0,T,z,cs=0,cs2=0;
cin>>n;
int cl[n+1][8];
for(int i=1;i<=n;i++){
    for(int j=1;j<=3;j++)
        cin>>cl[i][j];
        cs2=max(cl[i][1],cl[i][2]);
        cs2=max(cs2,cl[i][3]);
    if(cl[i][1]==cs2)
        {
        cl[i][4]=1;
        c1+=1;}
    else{
        if(cl[i][2]==cs2)
        {
        cl[i][4]=2;
        c2+=1;}
        else{
            cl[i][4]==3;
            c3+=1;
            }
        }
    cs=min(cl[i][1],cl[i][2]);
    cs=min(cs,cl[i][3]);

    if(cl[i][1]==cs){
        cl[i][7]=1;}
        else{
        if(cl[i][2]==cs){
        cl[i][7]=2;}
        else{
            cl[i][7]=3;}}
    cl[i][6]=6-cl[i][4]-cl[i][7];
    cl[i][5]=cl[i][6]-cl[i][4];
}
for(int ooooo=0;ooooo<=1;ooooo++){
    if(c1>n/2)
        T=c1-n/2;
    if(c2>n/2)
        T=c2-n/2;
    if(c3>n/2)
        T=c3-n/2;
    int TT[T];
    for(int i=1;i<=n;i++){
        if(cl[i][4]==1){
            if(i<=4){
            for(int ij=1;ij<=T;ij++){
                TT[ij]=i;}}
            else{
            for(int j=1;j<=T;j++){
                if(cl[i][5]<cl[TT[j]][5]){
                    TT[j]=i;
                    continue;
                }
                }}
            }
        }
    if(ooooo==0){
    for(int i=1;i<=n;i++){
        cl[i][5]=cl[i][6]-cl[i][7];
        cl[TT[i]][4]=cl[i][6];
    }}
}
for(int i=1;i<=n;i++) h=h+cl[i][cl[i][4]];
cout<<h;
}
fclose(stdin);
fclose(stdout);
return 0;
}
