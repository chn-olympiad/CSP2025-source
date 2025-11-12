#include<iostream>
using namespace std;
int a[201][201];
int main(){
    //freopen("seat.in","w",stdin);
    //freopen("seat.out","r",stdout);
    int n,m,b,c,s,h;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            h=a[1][1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s=0;
            if(a[i][j]<a[i+1][j+1]){
                s=a[i][j];
                a[i][j]=a[i+1][j+1];
                a[i+1][j+1]=s;
            }
            if(a[i][j]<a[i][j+1]){
                s=a[i][j];
                a[i][j]=a[i][j+1];
                a[i][j+1]=s;
            }
            if(a[i][j]<a[i+1][j-1]){
                s=a[i][j];
                a[i][j]=a[i+1][j-1];
                a[i+1][j-1]=s;
            }
            if(a[i][j]<a[i+1][j]){
                s=a[i][j];
                a[i][j]=a[i+1][j];
                a[i+1][j]=s;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            swap(a[i],a[m+1-i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==h){
                b=i;
                c=j;
            }
        }
    }
    cout<<b<<" "<<c;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
