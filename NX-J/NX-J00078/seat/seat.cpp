#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int n,m,max=INT_MIN,num=0,e=1,f=1;
cin>>n>>m;
int a[11][11],b[11][11]={ };
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
    cin>>a[i][j];
    max=a[1][1];
    }
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(a[i][j]>max){
            if(f<=m&&e%2==1){
                f=f+1;
                     if(f>m){
                        e++;f--;
                    }
                }
            else if(f<=m&&e%2==0){
                f=f-1;
                     if(f<1){
                        e++;f++;
                    }
                }
            }
        }
    }


cout<<e<<" "<<f;
return 0;
}
