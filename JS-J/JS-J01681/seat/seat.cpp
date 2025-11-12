#include<bits/stdc++.h>
using namespace std;
int stu[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int len=n*m;
    for(int i=0;i<len;i++){
        scanf("%d",&stu[i]);
        //cout<<stu[i]<<" ";
    }
    int mygrade=stu[0];
    sort(stu,stu+len);
    int mynum;
    for(int i=0;i<len;i++){
        //cout<<stu[i]<<" ";
        if(stu[i]==mygrade){
            mynum=len-i;
            break;
        }
    }
    //cout<<mynum<<endl;
    int ansx,ansy;//x wei lie,y wei hang.
    ansx=ceil((mynum+0.0)/n);
    if(ansx%2==1){
        if(mynum%n==0){
            ansy=n;
        }else{
            ansy=mynum%n;
        }
    }else{
        if(mynum%n==0){
            ansy=1;
        }else{
            ansy=n+1-(mynum%n);
        }
    }
    printf("%d %d",ansx,ansy);
    return 0;
}
