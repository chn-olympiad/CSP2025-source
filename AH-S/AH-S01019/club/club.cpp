#include<bits/stdc++.h>
using namespace std;
struct stu{
    int c1;
    int c2;
    int c3;
//    int l1;
 //   int l2;
 //   int l3;
    int bh;
};
int cmp1(stu x,stu y){
    if(x.c1>y.c1){
        return true;
    }return false;
}int cmp2(stu x,stu y){
    if(x.c2>y.c2){
        return true;
    }return false;
}int cmp3(stu x,stu y){
    if(x.c3>y.c3){
        return true;
    }return false;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        stu a1[100002]={};
        stu a2[100002]={};
        stu a3[100002]={};
        int a1s=0,a1h=0,a2s=0,a2h=0,a3s=0,a3h=0;
        int n;
        cin>>n;
        int sum1=0,sum2=0,sum3=0;
        for(int cnt=0;cnt<n;cnt++){
            stu as;
            cin>>as.c1>>as.c2>>as.c3;
            as.bh=0;
            //cout<<222;
            if(as.c1>=as.c2&&as.c2>=as.c3){
                //as.l1=1;
                //as.l2=2;
                //as.l3=3;
                a1s++;
                a1[a1s]=as;
                a1h+=as.c1;
            }else if(as.c1>=as.c3&&as.c2<=as.c3){
                //as.l1=1;
                //as.l2=3;
                //as.l3=2;
                a1s++;
                a1[a1s]=as;
                a1h+=as.c1;
            }else if(as.c1<=as.c2&&as.c2<=as.c3){
                //as.l1=3;
                //as.l2=2;
                //as.l3=1;
                a3s++;
                a3[a3s]=as;
                a3h+=as.c3;
            }else if(as.c1<=as.c2&&as.c1>=as.c3){
                //as.l1=2;
                //as.l2=1;
                //as.l3=3;
                a2s++;
                a2[a2s]=as;
                a2h+=as.c2;
            }else if(as.c1>=as.c2&&as.c3>=as.c1){
                //as.l1=3;
                //as.l2=1;
                //as.l3=2;
                a3s++;
                a3[a3s]=as;
                a3h+=as.c3;
            }else{
                //as.l1=2;
                //as.l2=3;
                //as.l3=1;
                a2s++;
                a2[a2s]=as;
                a2h+=as.c2;
            }
        }
        //cout<<111;
        sort(a1,a1+n,cmp1);
        sort(a2,a2+n,cmp2);
        sort(a3,a3+n,cmp3);
        //for(int i=0;i<a1s;i++){
          //  cout<<'a'<<a1[i].c1<<" ";
        //}cout<<endl;
        //for(int i=0;i<a2s;i++){
          //  cout<<a2[i].c2<<" ";
        //}cout<<endl;
        //for(int i=0;i<a3s;i++){
          //  cout<<'c'<<a3[i].c3<<" ";
        //}cout<<endl;
        if(a1s>n/2){
            for(int i=n/2+1;i<=a1s;i++){
                a1h-=a1[i].c1;
                if(a1[i].c2>=a1[i].c3&&a2s+1<=n/2||a3s+1>=n/2){
                   a2h+=a1[i].c2;
                   a2s++;
                }else{
                   a3h+=a1[i].c3;
                   a3s++;
                }
            }
        }else if(a2s>n/2){
            for(int i=n/2+1;i<=a2s;i++){
                a2h-=a2[i].c2;
                if(a2[i].c1>=a2[i].c3&&a1s+1<=n/2||a3s+1>=n/2){
                   a1h+=a2[i].c1;
                   a1s++;
                }else{
                   a3h+=a2[i].c3;
                   a3s++;
                }
            }
        }else if(a3s>n/2){
            for(int i=n/2+1;i<=a3s;i++){
                a3h-=a3[i].c3;
                if(a3[i].c1>=a3[i].c2&&a1s+1<=n/2||a2s+1>=n/2){
                   a1h+=a3[i].c1;
                   a1s++;
                }else{
                   a2h+=a3[i].c2;
                   a2s++;
                }
            }
        }
        cout<<a1h+a2h+a3h<<endl;
    }
    return 0;
}
