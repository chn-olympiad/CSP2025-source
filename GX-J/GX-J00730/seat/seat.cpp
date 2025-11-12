#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int r;
int a[1001]={};
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int len=n*m;
    for(int i=1;i<=len;i++){
        cin>>a[i];
        if(i==1) r=a[i];
    }
    sort(a+1,a+len+1,cmp);
    float t;
    for(int i=1;i<=len;i++){
        if(a[i]==r){
            t=i;
            break;
        }
    }
    int t1=t/n;   // xiao r suozaide lie
    int n1,m1=ceil(t/n);      //n1 hang m1 lie
//    cout<<m1;
    if(m1%2==1){   //jishulie  from up to down
        n1=t-n*(m1-1);
    }else{         //oushulie  from down to up
        n1=m1-(t-n*(m1-1))+1;
    }
    printf("%d %d",m1,n1);
    return 0;
}
