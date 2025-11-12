#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number1.in","r",stdin);
freopen("number1.out","w",stdout);
int s[11][11]={};
int n,m,a[101]={},b[101]={};
cin>>n>>m;
int sum=0;
for(int i=1;i<=m;i++){
        cin>>a[i];
        a[i]+=sum;
}
int p=sum/n*m;
if(a[1]>p){
    cout<<"q";
    }
for(int i=1;i<=m*n;i++){
        if(a[i]<a[i+1]){
            swap(a[i],a[i+1]);
        }
}
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        s[i][j]=a[i];
        a[2*n+1]=s[1][3];
        a[2*n]=s[1][2];
        cout<<s[i][j]<<" ";
    }
}


return 0;
}
