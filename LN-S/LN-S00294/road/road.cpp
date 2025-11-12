#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,b=1,ans=0;
    cin>>n;
int a[1000][1000];
for(int i=1;i<=3;i++){
for(int j=1;j<=n;j++){
        cin>>a[i][j];
}
}
for(int l=1;l<=n;l++){
        if(a[1][b]>a[2][b]&&a[1][b]>a[3][b]){
            ans+=a[1][b];
    }
    if(a[2][b]>a[1][b]&&a[2][b]>a[3][b]){
        ans+=a[2][b];
    }
    if(a[3][b]>a[1][b]&&a[3][b]>a[2][b]){
        ans+=a[3][b];
    }
    b++;
}
cout<<ans;
return 0;
}
