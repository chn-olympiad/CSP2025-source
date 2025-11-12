//GZ-S00329 贵阳市观山湖区第十三中学 王浚亦

#include<bits/stdc++.h>
using namespace std;
int n,t,da,xiao,zhong;
int r1,r2,r3,club1,club2,club3;
int a[100005],b[100005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t-=t;
        for(int j=1;j<=a[i];j++){
            for(int l=1;l<=3;l++){
               cin>>b[l];
               r1=b[l];
               r2=b[l-1];
               r3=b[l-2];
               da=max(r3,max(r2,r1));
               xiao=min(r3,min(r2,r1));
               zhong=r1+r2+r3-da-xiao;
               if(da==r1) club1++;
               if(da==r2) club2++;
               if(da==r3) club3++;
            }
            if(club1<=a[i]/2&&club2<=a[i]/2&&club3<=a[i]/2) t+=da;
            else t+=zhong;
        }
		cout<<t<<endl;
    }
    return 0;
}
