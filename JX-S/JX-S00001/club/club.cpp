#include<bits/stdc++.h>
using namespace std;
struct member{
    int a[5],maxn,midn,minn,cha,b;


}n[100005];
int t,n1,sum,c1[100005],cnt1,c2[100005],cnt2,c3[100005],cnt3,mincha=1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
     cin>>t;
    for(int i=1;i<=t;i++){
         int sum=0,c1[100005]={0},cnt1=0,c2[100005]={},cnt2=0,c3[100005]={},cnt3=0;
        cin>>n1;
        for(int j=1;j<=n1;j++){
           cin >>n[j].a[1]>>n[j].a[2]>>n[j].a[3];
          // n[j].maxn=max(max(n[j].a[1],n[j].a[2]),max(n[j].a[1],n[j].a[3]));
           n[j].minn=min(min(n[j].a[1],n[j].a[2]),min(n[j].a[1],n[j].a[3]));
           if(n[j].a[1]>n[j].a[2]&&n[j].a[1]>n[j].a[3]){c1[j]=n[j].a[1];cnt1++;sum+=c1[j];n[j].maxn=n[j].a[1];n[j].b=1;}
            else if(n[j].a[2]>n[j].a[1]&&n[j].a[2]>n[j].a[3]){c2[j]=n[j].a[2];cnt2++;sum+=c2[j];n[j].maxn=n[j].a[2];n[j].b=2;}
            else if(n[j].a[3]>n[j].a[1]&&n[j].a[3]>n[j].a[2]){c3[j]=n[j].a[3];cnt3++;sum+=c3[j];n[j].maxn=n[j].a[3];n[j].b=3;}
           n[j].midn=n[j].a[1]+n[j].a[2]+n[j].a[3]-n[j].maxn-n[j].minn;
           n[j].cha=n[j].maxn-n[j].midn;
        }
        if(cnt1>n1/2||cnt2>n1/2||cnt3>n1/2){
            //int cnt=max(max(cnt1,cnt2),max(cnt1,cnt3));
            int cnt,d;
            if(cnt1>n1/2){cnt=cnt1;d=1;}
            else if(cnt3>n1/2){cnt=cnt3;d=3;}
            else if(cnt2>n1/2){cnt=cnt2;d=2;}
            for (int k=1;k<=cnt-n1/2;k++){
            mincha=1;
            for(int j=1;j<=n1;j++){
                if(n[j].b==d&&n[j].cha<n[mincha].cha&&n[j].cha!=-1)mincha=j;
            }
            n[mincha].cha=-1;
            sum-=n[mincha].maxn;
            sum+=n[mincha].midn;
        }
    }
    cout<<sum<<endl;
    }
    return 0;
}
