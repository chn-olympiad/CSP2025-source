#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int n,m,t=0;
int i,j=0;
int a[10001][10001]={0};
int satisfy1[10001][10001];
int satisfy2[10001][10001];
int satisfy3[10001][10001];
int totalsatisfy[10001];

int cmp(int a,int b){
    return a>b;
}
int main(){

freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
fclose(stdin);
fclose(stdout);

std::cin>>t;

for(j=0;j<t;j++){
    cin>>n;
    for(i=1;i<n;i++){

    std::cin>>a[i][1]>>a[i][2]>>a[i][3];
    satisfy1[j][i]=a[i][1];
    satisfy2[j][i]=a[i][2];
    satisfy3[j][i]=a[i][3];

    }
}
int c=0;
for(c=1;c<(int)(n/2);c++){
    for(j=0;j<t;j++){
        for(i=1;i<n;i++){
            totalsatisfy[c]=satisfy1[j][i]+satisfy2[j][i]+satisfy3[j][i];
        }
    }
}
sort(totalsatisfy+0,totalsatisfy+n,cmp);

cout<<totalsatisfy[0];
return 0;


}
