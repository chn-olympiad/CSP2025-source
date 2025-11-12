#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    int a[1000];
    int sum=0;
    cin>>n;
    int i1,i2,i3;
    for(int i=1;i<=t;i++){
            /*for(int j=1;j<=n;j++){
                cin>>i1>>i2>>i3;
                if((i1>i2)&&(i1>i3)){
                    sum+=i1;
                }else if((i2>i1)&&(i2>i3)){
                    sum+=i2;
                }else if((i3>i1)&&(i3>i2)){
                    sum+=i3;
                }cout<<sum<<endl;
            sum=0;
        */
            for(int j=1;j<=n*3;j+=3){
                cin>>a[j]>>a[j+1]>>a[j+2];
                if((a[j]>a[j+1])&&(a[j]>a[j+2])){
                        sum+=a[j];
                    }else if((a[j+1]>a[j])&&(a[j+1]>a[j+2])){
                        sum+=a[j+1];
                    }else if((a[j+2]>a[j])&&(a[j+2]>a[j+1])){
                        sum+=a[j+2];
                    }
            }cout<<sum<<endl;
                    sum=0;
        }
    return 0;
}
