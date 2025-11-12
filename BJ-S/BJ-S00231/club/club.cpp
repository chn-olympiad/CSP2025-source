#include<bits/stdc++.h>
using namespace std;
int t,n,c[100009];

struct zong{
int l1,l2,l3;};
zong a[100009];
int  pan1(zong k){
    int ci=-1,da=k.l3;
    if(k.l2>=da){
        da=k.l2;
        ci=da;
    }if(k.l1>=da){
        da=k.l1;
        ci=da;

    }else if(k.l1>=ci){
        ci=k.l1;
    }
    return da;
}
int  pan2(zong k){
  /*  int ci=-1,da=k.l3;
    if(k.l2>=da){
        da=k.l2;
        ci=da;
    }else{ci=k.l2;}
    if(k.l1>=da){
        da=k.l1;
        ci=da;return ci;

    }else if(k.l1>=ci){
        ci=k.l1;
    }*/
    if(k.l1<=k.l2){
        if(k.l2<=k.l3)return k.l2;
        else{
            if(k.l1<=k.l3)return k.l3;
            else return k.l1;
        }
    }else{
        if(k.l3<=k.l2)return k.l2;
        else{
            if(k.l1>=k.l3)return k.l3;
            else return k.l1;
        }
    }



}
bool pan(zong k,zong l){
    return pan1(k)-pan2(k)>=pan1(l)-pan2(l);
}
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
int t;int yy=0;
cin>>t;
for(int i=1;i<=t;i++){
        yy=0;
    cin>>n;
    for(int j=1;j<=n;j++){
        cin>>a[j].l1>>a[j].l2>>a[j].l3;


    }
    sort(a+1,a+n+1,pan);
    int p1=0,p2=0,p3=0;
    for(int j=1;j<=n;j++){
        int o=0;
        if(a[j].l1==pan1(a[j]) and p1+1<=n/2){
            yy+=pan1(a[j]);p1++;o=1;//cout<<yy<<endl;
        }

        if(a[j].l2==pan1(a[j]) and p2+1<=n/2 and o==0){
            yy+=pan1(a[j]);p2++;o=1;//cout<<yy<<endl;
        }
        if(a[j].l3==pan1(a[j]) and p3+1<=n/2 and o==0){
                p3++;yy+=pan1(a[j]);o=1;//cout<<yy<<endl;
}
        if(o==0){
            if(a[j].l1==pan2(a[j]) and p1+1<=n/2){
            yy+=pan2(a[j]);p1++;o=1;
        }
//out<<a[j].l1<<endl;cout<<a[j].l2<<endl;cout<<a[j].l3<<endl<<pan2(a[j])<<endl;
        if(a[j].l2==pan2(a[j]) and p2+1<=n/2 and o==0){
            yy+=pan2(a[j]);p2++;o=1;
        }
        if(a[j].l3==pan2(a[j]) and p3+1<=n/2 and o==0){
                p3++;yy+=pan2(a[j]) ;o=1;}
        }o=1;
    }cout<<yy<<endl;

}
return 0;
}
