#include<bits/stdc++.h>
using namespace std;
struct r{
    int num,id;
}a[105];
bool cmp(r a,r b){
    return a.num>b.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,m1=1,n1=0,num1id;//nhang mlie
    bool ul=true;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>a[i].num;
        a[i].id=i;
    }
    sort(a+1,a+1+m*n,cmp);
    for(int i=1;i<=m*n;i++){
        if(a[i].id==1){
            num1id=i;
        }
    }
    for(int i=1;i<=num1id;i++){
        if(n1<n&&ul!=0){
            n1++;
        }
        else if(n1<n&&ul==0){
            n1--;
        }
        else if(n1==n&&ul==0){
            n1--;
        }
        else if(n1==n&&ul!=0){
            m1++;
            ul=false;
        }
        else if(n1==1&&ul==0){
            m1++;
            ul=true;
        }
    }
    cout<<m1<<' '<<n1;
    return 0;
}
