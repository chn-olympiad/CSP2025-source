#include<iostream>
#include<bits.stdc++/h>
using namespace std;
int an[100005][5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("clud.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)
        {
            cin>>an[i][j]>>endl;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            a[i][j]=an[j][i];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<n-1;j++){
            if(a[i][j]<a[i][j+1]){
                int tt=a[i][j+1];
                a[i][j+1]=a[i][j];
                a[i][j]=t;
            }
        }
    }
    int sum=0;
    int aa=0,bb=0,cc=0;
    int a1=0,a2=0,a3=0;
    int k[5]={0,1,2};
    for(int i=0;i<n;i++){
        if(a[0][a1]>a[1][a2] && a[0][a1]>a[2][a3] && aa<=n/2){
            sum+=a[0][a1];
            a1++;
            aa++;
        }
        if(a[1][a2]>a[0][a1] && a[1][a2]>a[2][a3] && bb<=n/2){
            sum+=a[1][a2];
            a2++;
            bb++;
        }
        if(a[2][a3]>a[0][a1] && a[2][a3]>a[1][a2] && cc<=n/2){
            sum+=a[2][a3];
            a3++;
            cc++;
        }
    }
    cout<<sum<<endl;
    return 0;

}
