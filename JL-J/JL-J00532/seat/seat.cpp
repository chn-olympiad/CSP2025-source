#include<bits/stdc++.h>
using namespace std;
int a[110];
int x[110];
int y[110];
int xns,yns;
int main(){
    //there is nothing I can do at know?
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int t;
    for(int i=1;i<=n*m;i++){
      cin>>a[i];
      t=a[1];
    }
    sort(a+1,a+1+n);
    int i=1;
    for(int j=1;j<=m;){
        if(i<n){
            for(int i=1;i<=n;i++){
                x[xns++]=i;
                y[yns++]=j;
            }
        }
        else if(i==n){
            j++;
            for(int i=n;i>=1;i--){
                x[xns++]=i;
                y[yns++]=j;
            }
        }

    }
    int q;
for(int i=1;i<=n*m;i++){
    if(a[i]==t)q=i;
}
cout<<x[q]<<" "<<y[q];
 return 0;
}

