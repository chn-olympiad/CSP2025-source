#include<bits/stdc++.h>
using namespace std;
int main(){
freopen ("club.in","r",stdin);
freopen ("club.out","w",stdout);
int a,b[101][101][101],d[101];
cin>>a;
for(int i=0;i<a;i++){
        cin>>d[i];
for(int j=0;j<d[i];j++){
    for(int k=0;k<3;k++){
        cin>>b[i][j][k];
    }
}
}
    int t[10001]={0},i=0;
    while(i<a){
    int o=0,j=0,m=0,n=0;
    while(n<d[i]){
        int w=0,q=0,e=0;
        while(q+w+e<d[i]&&w<d[i]/2&&j<d[i]){
            t[o]+=b[i][j][0];
            w++;
            j++;
        }
        while(q+w+e<d[i]&&q<d[i]/2&&m<d[i]){
            t[o]+=b[i][m][1];
            q++;
            m++;
        }
        while(q+w+e<d[i]&&e<d[i]/2&&n<d[i]){
            t[o]+=b[i][n][2];
            e++;
            n++;
        }
        o++;
    }
    sort(t,t+o);
    cout<<t[o]<<endl;
    i++;
}
fclose(stdin);
fclose(stdout);
return 0;
}
