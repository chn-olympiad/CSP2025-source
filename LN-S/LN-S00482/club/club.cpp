#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
bool comp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a1,a2,a3;
        bool spa=true,spb=true;
        for(int j=0;j<n;j++){
            cin>>a1>>a2>>a3;
            if(a2!=0||a3!=0){
                spa=false;
            }
            if(a3!=0){
                spb=false;
            }
            a[j]=a1;
            b[j]=a2;
            c[j]=a3;
        }
        if(spa==true){
            int sum=0;
            int t=n/2;
            int t23=n-t;
            sort(a,a+n,comp);
            for(int j=0;j<t;j++){
                sum+=a[j];
            }
            cout<<sum;
        }
        else if(n==2){
            int all[6]={};
            all[0]=a[0];
            all[1]=b[0];
            all[2]=c[0];
            all[3]=a[1];
            all[4]=b[1];
            all[5]=c[1];
            int maxx=all[0];
            for(int j=0;j<6;j++){
                maxx=max(all[j],maxx);
            }
            bool isin=true;
            for(int j=0;j<3;j++){
                if(maxx=all[j]){
                    isin=false;
                }
            }
            int maxx2=0;
            if(isin=false){
                for(int j=0;j<3;j++){
                    maxx2=max(all[j],maxx2);
                }
                cout<<maxx+maxx2;
            }
            else{
                for(int j=3;j<6;j++){
                    maxx2=max(all[j],maxx2);
                }
                cout<<maxx+maxx2;
            }
        }
        else{
            cout<<a1+a2-2+a3;
        }
    }
    return 0;
}
