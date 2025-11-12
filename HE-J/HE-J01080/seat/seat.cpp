#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen ("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,c;
    cin>>n>>m;
    int seat[11][11]={};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    c=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=i;j++){
            if(a[i]>a[j])swap(a[i],a[j]);
        }
    }
    int k=1;
    for(int i=1;i<=n;i++){

        if(i%2==1){
                for(int j=1;j<=m;j++){
                    seat[i][j]=a[k];
                    k++;
                   if(seat[i][j]==c){
                    cout<<i<<" "<<j;
                   }
                }
            }
        else{
            for(int j=m;j>=1;j--){
                seat[i][j]=a[k];
                k++;
                if(seat[i][j]==c){
                    cout<<i<<" "<<j;
                   }
            }
        }

    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

