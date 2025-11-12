#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++){
        int n,b[6]={0},a[100005][3]={0};
        cin>>n;
        int sum=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++){
            cin>>a[i][j];
            }
            if(n==2){
                b[0]=a[1][1]+a[2][2];
                b[1]=a[1][1]+a[2][3];
                b[2]=a[1][2]+a[2][1];
                b[3]=a[1][2]+a[2][3];
                b[4]=a[1][3]+a[2][1];
                b[5]=a[1][3]+a[2][2];

        }
        sort(b,b+6,cmp);
        cout<<b[0]<<endl;
    }
    return 0;

}
