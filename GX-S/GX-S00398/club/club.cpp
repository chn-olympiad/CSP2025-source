#include<iostream>  //pianfen chuang qiji dabiao chu shengyi
#include<algorithm>
using namespace std;
int T;
int n;
const int N=1e5+7;
struct member{
    int s1,s2,s3;
    int num;
};
member a[N]={};
bool cmp(member x,member y){
    return x.s1>y.s1;
}
bool cmp2(int x,int y){
    return x>y;
}
bool cmp3(int x,int y){
    return x<y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==2){  //n=2tepan
        int a1[1001]={},a2[1001]={};
        int mx1=-1,mx2=-1;
        int flag1,flag2;
        for(int i=1;i<=3;i++){
            cin>>a1[i];
            if(a1[i]>mx1){
            mx1=a1[i];
            flag1=i;
        }
        }
        for(int i=1;i<=3;i++){
            cin>>a2[i];
            if(a2[i]>mx2){
            mx2=a2[i];
            flag2=i;
        }
        }
        if(flag1!=flag2){
                int ans=mx1+mx2;
            cout<<ans<<endl;
        }else{
        sort(a1+1,a1+1+3);
        sort(a2+1,a2+1+3);
        if(a1[2]+a2[3]>=a2[2]+a1[3]){
            int ans=a1[2]+a2[3];
            cout<<ans<<endl;
        }else{
            int ans=a1[3]+a2[2];
            cout<<ans<<endl;
        }
        }
 //       sort(a1+1,a1+1+3);
 //       sort(a2+1,a2+1+3);
 //       if(a1[3]==a2[3]){
  //          int mx3=max(a1[2],a2[2]);
  //          int ans=mx3+a1[3];

        }else if(n==4){   //n=4tepan
            long long ss=0;
            for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i].num=i;
            a[i].s1=x;
            a[i].s2=y;
            a[i].s3=z;
            ss+=a[i].s1;
        }
        cout<<ss<<endl;
        }else{         //di 12 ge ceshidian tepan
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i].num=i;
            a[i].s1=x;
            a[i].s2=y;
            a[i].s3=z;
        }
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n/2;i++){
        ans+=a[i].s1;
    }
    cout<<ans<<endl;
    }
    }
    return 0;
}
