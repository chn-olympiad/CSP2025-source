#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int num[200]={0},k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>k;
    num[0]=k;
    for(int i=1;i<n*m;i++){
        cin>>num[i];
    }
    sort(num,num+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(num[i]==k){
            int mc=i+1;
            int y=(mc+n-1)/n;
            int x;
            if(y%2==0){
                int l=mc%n;
                if(l==0)l=n;
                x=n+1-l;
            }
            else{
                x=mc%n;
                if(x==0){
                    x=n;
                }
            }
            cout<<y<<' '<<x;
            break;
        }
    }
    return 0;
}

