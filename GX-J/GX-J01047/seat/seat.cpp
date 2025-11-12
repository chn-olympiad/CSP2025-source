#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int a,b,r,ans,t1;
int m[100],t[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a*b;i++){
        cin>>m[i];
    }
    r=m[0];
    sort(m,m+a*b+1,cmp);
    for(int i=0;i<a*b;i++){
        if(m[i]==r){
            ans=i+1;
        }
    }
    for(int i=1;i<=b;i++){
        if(i%2!=0){
            for(int j=1;j<=a;j++){
                t1++;
                if(t1==ans){
                    cout<<i<<" "<<j;
                }
            }
        }
        else{
            for(int j=a;j>0;j--){
                t1++;
                if(t1==ans){
                    cout<<i<<" "<<j;
                }
            }
        }
    }
    return 0;
}
