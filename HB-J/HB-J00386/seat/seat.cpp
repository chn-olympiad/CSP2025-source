#include <bits/stdc++.h>
using namespace std;
int a,b;
int c;
long long cxy[10010];
long long sjdy[100][100];
bool cxy2(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
cin>>a>>b;
int cxy1=0;
for(int i=0;i<a*b;i++){
    cin>>cxy[i];
}
c=cxy[0];
sort(cxy,cxy+a*b,cxy2);
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        sjdy[i][j]=cxy[cxy1];
        cxy1++;
    }
    i++;
    for(int j=b;j>=1;j--){
        sjdy[i][j]=cxy[cxy1];
        cxy1++;
    }
}
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        if(sjdy[i][j]==c){
            cout<<i<<" "<<j;
        }
    }
}
return 0;
}
