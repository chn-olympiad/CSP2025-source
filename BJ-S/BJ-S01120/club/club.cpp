#include<bits/stdc++.h>
using namespace std;
struct Node{
    int _1=0,_2=0,_3=0;
    bool f=false;
}a[100010];
void cmp1(Node _x1,Node _y1){
    return _x1._1>=_y1._1;
}
void cmp2(Node _x2,Node _y2){
    return _x2._2>=_y2._2;
}
void cmp3(Node _x3,Node _y3){
    return _x3._3>=_y3._3;
}
int main(){
   //freopen("club.in","w",stdin);
   //freopen("club,out","r",stdout);
   int t,n,x;
   cin>>t;
   while(t--){
        int dq=0,zd=INT_MIN;
        cin>>n;
        x=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i]._1>>a[i]._2>>a[i]._3;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                for(int k=1;k<=n-i-j;k++){
                        int _u=i-j,_v=b-c,_w=a-c;
                        if((abs(_u)>=x||abs(_v)>=x||abs(_w)>=x)&&i+j+k==n) continue;

                    sort(a+1,a+1+n,cmp1);
                    for(int __1=1;__1<=i;__1++){
                        dq+=a[i]._1;
                        a[i].f=true;
                    }

                    sort(a+1,a+1+n,cmp2);
                    for(int __1=1;__1<=i;__1++){
                        if(a[j].f==true) continue;
                        dq+=a[j]._1;
                        a[j].f=true;
                    }

                    sort(a+1,a+1+n,cmp3);
                    for(int __1=1;__1<=i;__1++){
                        if(a[k].f==true) continue;
                        dq+=a[k]._1;
                        a[k].f=true;
                    }
                    zd=max(zd,dq);
                }
            }
        }
        cout<<zd;
        for(int i=1;i<=n;i++){
            a[i].f=false;
        }
   }
    return 0;
}
