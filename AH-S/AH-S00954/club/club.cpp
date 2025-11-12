#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=200050;
int a[MAXN][3],n,c[MAXN];
void solve(){
    cin>>n;
    int cnt0=0,cnt1=0,cnt2=0;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        int mx=max(a[i][0],max(a[i][1],a[i][2]));
        if(mx==a[i][0])cnt0++,c[i]=0;
        else if(mx==a[i][1])cnt1++,c[i]=1;
        else cnt2++,c[i]=2;
        sum+=mx;
    }
    if(cnt1>n/2){
        for(int i=1;i<=n;i++){
            swap(a[i][0],a[i][1]);
            if(c[i]<2)c[i]=1-c[i];
        }
        swap(cnt0,cnt1);
    }else if(cnt2>n/2){
        for(int i=1;i<=n;i++){
            swap(a[i][0],a[i][2]);
            if(c[i]!=1)c[i]=2-c[i];
        }
        swap(cnt0,cnt2);
    }
    if(cnt0<=n/2){
        cout<<sum<<endl;
        return;
    }
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i=1;i<=n;i++){
        if(c[i]==0)q.push(a[i][0]-max(a[i][1],a[i][2]));
    }
    for(int i=n/2+1;i<=cnt0;i++){
        sum-=q.top();
        q.pop();
    }
    cout<<sum<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
