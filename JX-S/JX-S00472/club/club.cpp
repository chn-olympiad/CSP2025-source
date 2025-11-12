#include<iostream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[3],d[100];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[0];
            cin>>a[1];
            cin>>a[2];
            if(a[0]>a[1]>a[2] || a[0]>a[2]>a[1]){
                d[0]+=1;
            }else if(a[1]>a[0]>a[2] || a[1]>a[2]>a[0]){
                d[1]+=1;
            }else{
                d[2]+=1;
            }





        }


    }



}
