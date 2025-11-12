#include<bits/stdc++.h>
using namespace std;
struct ciaf{
    int fir,sec,thi;
}h[100005];
int n,cnt;
int q;
void dfs(int count1,int g,int a1,int b1,int c1){
    int k=(n>>1);//n>>1 -> n/2.
    //question's back -> n/2 -> stop and choose max satisfied points.
    //cout<<count1<<" "<<f<<" "<<a1<<""<<b1<<" "<<c1<<endl;
    if(count1==n+1||a1>k||b1>k||c1>k){cnt=max(cnt,g);return;}
    int e=a1+1;
    int r=b1+1;
    int t=c1+1;
    int ncount=count1+1;
    if(e<=k)dfs(ncount,g+h[count1].fir,e,b1,c1);
    if(r<=k)dfs(ncount,g+h[count1].sec,a1,r,c1);
    if(t<=k)dfs(ncount,g+h[count1].thi,a1,b1,t);
}
int main(){
    //in and out
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>q;
    while(q--){
        cin>>n;
        //O(3^n) ->n<=30 , I hope so =(.
        if(n<=40){
            cnt=0;
            for(int i=1;i<=n;i++)cin>>h[i].fir>>h[i].sec>>h[i].thi;
            //all count=1,satisfied points=0,fir's a1=0,sec's b1=0,thi's c1=0.
            dfs(1,0,0,0,0);
            //anser
            cout<<cnt<<endl;
        }
        else {
            //special when a(i,2) and a(i,3) both were 0,then cout sum half_first_sum.
            for(int i=1;i<=n;i++)if(h[i].sec==0)cnt++;
            for(int i=1;i<=n;i++)if(h[i].thi==0)cnt++;
            if(cnt==2*n){
                int sum=0,l[100005];
                memset(l,0,sizeof(l));
                for(int i=1;i<=n;i++)l[i]=h[i].fir;
                sort(l+1,l+n+1);//from the biggest num to half num and add them to sum.
                for(int i=n;i>n/2;i--)sum+=l[i];
                cout<<sum<<endl;
                continue;
            }
        }
    }
    return 0;
}
