#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y,z;
}a[100005],b[100005],c[100005],d[100005];

bool cmp1(node a,node b){
    return a.x>b.x;
}

bool cmp2(node a,node b){
    return a.y>b.y;
}

bool cmp3(node a,node b){
    return a.z>b.z;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,lim,ans1=0,ans2=0,ans3=0;
        cin>>n;
        lim=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            b[i].x=a[i].x,b[i].y=a[i].y,b[i].z=a[i].z;
            c[i].x=a[i].x,c[i].y=a[i].y,c[i].z=a[i].z;
            d[i].x=a[i].x,d[i].y=a[i].y,d[i].z=a[i].z;
        }
        sort(b+1,b+n+1,cmp1);
        sort(c+1,c+n+1,cmp2);
        sort(d+1,d+n+1,cmp3);
        int vis11=0,vis12=0,vis13=0,vis21=0,vis22=0,vis23=0,vis31=0,vis32=0,vis33=0;
        for(int i=1;i<=n;i++){
            int maxx1=max(b[i].x,max(b[i].y,b[i].z));
            if(maxx1==b[i].x&&vis11<lim){
                vis11++;
                ans1+=b[i].x;
            }
            else if(maxx1==b[i].y&&vis12<lim){
                vis12++;
                ans1+=b[i].y;
            }
            else if(maxx1==b[i].z&&vis13<lim){
                vis13++;
                ans1+=b[i].z;
            }
            int maxx2=max(c[i].x,max(c[i].y,c[i].z));
            if(maxx2==c[i].x&&vis21<lim){
                vis21++;
                ans2+=c[i].x;
            }
            else if(maxx2==c[i].y&&vis22<lim){
                vis22++;
                ans2+=c[i].y;
            }
            else if(maxx2==c[i].z&&vis23<lim){
                vis23++;
                ans2+=c[i].z;
            }
            int maxx3=max(d[i].x,max(d[i].y,d[i].z));
            if(maxx3==d[i].x&&vis31<lim){
                vis31++;
                ans3+=d[i].x;
            }
            else if(maxx3==d[i].y&&vis32<lim){
                vis32++;
                ans3+=d[i].y;
            }
            else if(maxx3==d[i].z&&vis33<lim){
                vis33++;
                ans3+=d[i].z;
            }
        }
        cout<<max(ans1,max(ans2,ans3))<<endl;
    }
    return 0;
}
