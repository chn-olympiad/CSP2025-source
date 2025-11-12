#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club1.in","r",stdin);
    freopen("club.out","w",stdout);
    int x,y,k;
    long long summ=0;
    cin>>x;
    int a[100010][5],b[100010],c[100010],d[100010];
    for(int i=1;i<=x;i++){
        cin>>y;
        k=y/2;
        for(int j=1;j<=y;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        for(int j=1;j<=y;j++){
            b[j]=a[j][1];
        }

        sort(b+1,b+y+1);
        for(int j=y;j>=k+1;j--){
            summ+=b[j];
        }
        for(int j=1;j<=y;j++){
            c[j]=a[j][2];
        }
        sort(c+1,c+y+1);
        for(int j=y;j>=k+1;j--){
            summ+=c[j];
        }
        for(int j=1;j<=y;j++){
            d[j]=a[j][3];
        }
        sort(d+1,d+y+1);
        for(int j=y;j>=k+1;j--){
            summ+=d[j];
        }
        cout<<summ<<endl;
        summ=0;
    }
    return 0;
}
