#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2){
    return a1>a2;
}
bool cmp2(int a1,int a2){
    return a1<a2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1]={0},num[n*m+1]={0};
    for(int i=1;i<=n*m;i++)
        cin>>num[i];
    int flag=num[1];
    sort(num+1,num+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==0)
            sort(num+m*(i-1)+1,num+m*(i)+1,cmp2);
    }
    for(int j=1;j<=n;j++){
            for(int i=1;i<=m;i++){
                a[j][i]=num[i*n-(m-j)+1];
                if(a[j][i]==flag){
                   cout<<i<<' '<<j;
                }
            }
    }
    cout<<endl;
    for(int i=1;i<=n*m;i++)
        cout<<num[i]<<' ';
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
