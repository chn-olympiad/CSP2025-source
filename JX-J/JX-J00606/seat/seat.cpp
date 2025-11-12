#include <bits/stdc++.h>
using namespace std;
int seat[20][20],xiao,a[2000],b[2000];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    xiao=b[1];
    sort(b,b+n*m+1);
    int l=1;
    for(int i=n*m;i>0;i--){
        a[l]=b[i];
        l++;
    }
    cout<<endl;
    int k=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){


                if(a[k]==xiao){
                    cout<<i<<" "<<j;
                    return 0;}

                k++;
            }
        }
        else{
            for(int j=n;j>=1;j--){

                if(a[k]==xiao){
                    cout<<i<<" "<<j;
                    return 0;}

                k++;
            }
        }
    }

    return 0;
}
