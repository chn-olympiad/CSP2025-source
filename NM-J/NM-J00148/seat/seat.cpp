#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m=0,n=0,a[105]={0},b=0,x=0;
    cin>>n>>m;
    cin>>a[1];
    x=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[i-1]){
            b=a[i];
            a[i]=a[i-1];
            a[i-1]=b;
        }
    }
    b=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            b++;
            if(a[b]==x){
                if(i%2==0){
                    cout<<i<<" "<<n-j+1;
                }else{
                    cout<<i<<" "<<j;
                }
                break;
            }
        }
        if(a[b]==x){
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
