#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[100]={0};
    int i=1;
    while(i<=n*m){
        cin>>a[i];
        i++;
    }
    int R=a[1],r;
    sort(a,a+i,cmp);
    for(int i=1;i<n*m;i++){
        if(a[i]==R){
            r=i+1;
            break;
        }
    }
    int f[n+1][m+1];
    int s=1,j=1;
    i=1;
    while(i<=n&&j<=m){
        f[i][j]=s;
        s++;
        if(j%2==1){
            if(i+1>n){
                j++;
            }
            else{
                i++;
            }
        }
        else{
            if(i-1==0){
                j++;
            }
            else{
                i--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(r==f[i][j]){
                cout<<j<<' '<<i;
                break;
            }
        }
        cout<<endl;
    }
    return 0;

}
