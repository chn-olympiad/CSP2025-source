#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 int m,cnt=0,c=0,d=1,n,b[105]={},a[12][12]={};
 cin>>m>>n;
 c=n*m;
 for(int i=1;i<=c;i++){
    cin>>b[i];
 }
 cnt=b[1];
 sort(b+1,b+c+1);
 for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        a[i][j]=b[d];
        d++;
    }
 }
 for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(a[i][j]==cnt) cout<<i<<j;
    }
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
