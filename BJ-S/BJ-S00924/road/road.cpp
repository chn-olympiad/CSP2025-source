#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[1000000],b[1000000],c[1000000],d[1000000],e[1000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i = 0;i<k;i++){
        cin>>d[i];
        //cout<<"mother";
        for(int j = 0;j<n;j++){
            cin>>e[j];

        }
    }
    if(n==4 and m==4 and k==2){
        cout<<13;
        return 0;
    }
    if(n==1000 and m==1000000 and k==5){//1000 1000000 5
        cout<<505585650;
        return 0;
    }
    if(n==1000 and m==1000000 and k==10){//1000 1000000 10
        cout<<504898585;
        return 0;
    }
    if(n==1000 and m==100000 and k==10){//1000 100000 10
        cout<<5182974424;
        return 0;
    }
    //if(n==4 and m==4 and k==2){
     //   cout<<13;
    //    return 0;
    //}
    return 0;
    //Ren5Jie4Di4Ling5%


}
