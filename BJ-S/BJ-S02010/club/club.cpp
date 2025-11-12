#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#include<stdio.h>
struct myd{
    int a,b,c;
}arr[100001];
bool cmp(myd x,myd y){
    if(x.a==y.a){
        if(x.b==y.b)return x.c>=y.c;
        return x.b>y.b;
    }
    return x.a>y.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t,n;
    cin>>t;
    bool allb0,allc0;
    while(t--){
        allb0=allc0=true;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i].a>>arr[i].b>>arr[i].c;
            if(arr[i].b)allb0=false;
            if(arr[i].c)allc0=false;
        }
        if(allb0 && allc0){
            priority_queue<int> pq;
            int ans=0;
            for(int i=1;i<=n;i++)pq.push(arr[i].a);
            for(int i=1;i<=(n/2);i++){
                ans+=pq.top();
                pq.pop();
            }
            cout<<ans;
            continue;
        }else if(n==2){
             cout<<max(arr[1].a+arr[2].b,max(arr[1].a+arr[2].c,max(arr[1].b+arr[2].c,max(arr[2].a+arr[1].b,max(arr[2].a+arr[1].c,arr[2].b+arr[2].c)))));
        }
    }
    return 0;
}