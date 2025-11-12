#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,flag=1,arr[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==0)flag=0;
        if(arr[i]!=0&&arr[i]!=1){flag=-1;break;}
    }
    if(flag==-1){
        cout<<0;
        return 0;
    }
    if(k==0&&flag){
        cout<<n/2;
    }
    if(k==0&&!flag){
        int cnt=0,ans=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==0){
                ans++;
                ans+=cnt/2;
                cnt=0;
            }
            else cnt++;
        }
        cout<<ans;
    }
    if(k==1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==1)cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
/*
diary,written from 11:19
I am a Grade 8 student in Zhenjiang.This is my second time to take part in CSP-J,also the last time.
I got the national first prize last year,but maybe I can only get a worse one this time.
T1 and T2 are both easy.What I can only wish is to AC them,just like the ones last year.
T3 is a little difficult to me.
Maybe it needs a qian2zhui4yi4huo4he2 to go faster,I think.
Maybe it needs a two-fen1,I think.
But that's all I can do.
I only try to get some easy points,at most 30.
T4 is also difficult to me.
two-hand(shuang1zhi3zhen1?I'm poor at English)may be helpful.
But I don't know how to solve other solutions,except 3-sides-polygon.
So I also just try to get some special points,at most 36.
Maybe I can get 266 in total,Maybe not.
At least,the score can be accepted.
Now it's 11:30.I will stop writing to check my code soon.
rp+1,for both CSP-J/S.
*/
