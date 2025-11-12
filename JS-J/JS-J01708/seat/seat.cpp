#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
  return x>y;
}
int a[1009];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++)cin>>a[i];
    int flag,flag1=a[1];
    sort(a+1,a+1+sum,cmp);
    for(int i=1;i<=sum;i++){
        if(a[i]==flag1){
            flag=i;
            break;
        }
    }
    int ansn=flag/n,ansm=flag%n;
    if(ansn%2==1){
        if(ansm==0){
            ansn=ansn;ansm=m;
        }
        else{
            ansn++;ansm=m-ansm+1;
        }
    }
    else if(ansn%2==0){
        if(ansm==0){
            ansn=ansn;ansm=1;
        }
        else{
            ansn++;ansm=ansm;
        }
    }
    cout<<ansn<<" "<<ansm;
    return 0;
}
