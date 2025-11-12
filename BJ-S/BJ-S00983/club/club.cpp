#include<bits/stdc++.h>
//#define int long long
using namespace std;
int t;
int n;
int a[100005][5];
struct box{
    int x,y;//最大值，第二大值
    int ax,ay;//他们的部门
}ans[100005];
int ct;
int cnt[5];
bool cmp(box x,box y){
    return (x.x-x.y)<(y.x-y.y);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ct=cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int kk=max(max(a[i][1],a[i][2]),a[i][3]);
            if(kk==a[i][1]){
                ans[i].x=kk;
                ans[i].ax=1;
                if(a[i][2]>=a[i][3]){
                    ans[i].y=a[i][2];
                    ans[i].ay=2;
                }
                else{
                    ans[i].y=a[i][3];
                    ans[i].ay=3;
                }
            }
            else if(kk==a[i][2]){
                ans[i].x=kk;
                ans[i].ax=2;
                if(a[i][1]>=a[i][3]){
                    ans[i].y=a[i][1];
                    ans[i].ay=1;
                }
                else{
                    ans[i].y=a[i][3];
                    ans[i].ay=3;
                }
            }
            else if(kk==a[i][3]){
                ans[i].x=kk;
                ans[i].ax=3;
                if(a[i][1]>=a[i][2]){
                    ans[i].y=a[i][1];
                    ans[i].ay=1;
                }
                else{
                    ans[i].y=a[i][2];
                    ans[i].ay=2;
                }
            }
            ct+=ans[i].x;
            cnt[ans[i].ax]++;
        }
        if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
            cout<<ct<<endl;
            continue;
        }
        sort(ans+1,ans+1+n,cmp);
        if(cnt[1]>n/2){
            int kk=cnt[1]-n/2;
            int cntt=0;
            for(int i=1;i<=n;i++){
                if(cntt==kk) break;
                if(ans[i].ax!=1) continue;
                cntt++;
                ct=ct-ans[i].x+ans[i].y;
            }
        }
        else if(cnt[2]>n/2){
            int kk=cnt[2]-n/2;
            int cntt=0;
            for(int i=1;i<=n;i++){
                if(cntt==kk) break;
                if(ans[i].ax!=2) continue;
                cntt++;
                ct=ct-ans[i].x+ans[i].y;
            }
        }
        else if(cnt[3]>n/2){
            int kk=cnt[3]-n/2;
            int cntt=0;
            for(int i=1;i<=n;i++){
                if(cntt==kk) break;
                if(ans[i].ax!=3) continue;
                cntt++;
                ct=ct-ans[i].x+ans[i].y;
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}
/*

*/
