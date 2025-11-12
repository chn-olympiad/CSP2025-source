#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
priority_queue<int,vector<int>,greater<int> >a1,a2,a3;
int a[6][maxn],cnt[maxn];
int cp(int a,int b,int c){
    if(a>b){
        if(c>a)
            return 3;
        else{
            return 1;
        }
    }
    else{
        if(c>b)
            return 3;
        else
            return 2;
    }
}
void solve(int n){
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[1][i]>>a[2][i]>>a[3][i];
        ans+=a[cp(a[1][i],a[2][i],a[3][i])][i];
        cnt[cp(a[1][i],a[2][i],a[3][i])]++;
        if(cp(a[1][i],a[2][i],a[3][i])==1){
            a1.push(min(a[1][i]-a[2][i],a[1][i]-a[3][i]));
        }
        if(cp(a[1][i],a[2][i],a[3][i])==2){
            a2.push(min(a[2][i]-a[1][i],a[2][i]-a[3][i]));
        }
        if(cp(a[1][i],a[2][i],a[3][i])==3){
            a3.push(min(a[3][i]-a[1][i],a[3][i]-a[2][i]));
        }
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]>(n/2)){
            if(i==1){
                while(cnt[i]>(n/2)){
                    int q=a1.top();
                    a1.pop();
                    ans-=q;
                    cnt[i]--;
                }
            }
            if(i==2){
                while(cnt[i]>(n/2)){
                    int q=a2.top();
                    a2.pop();
                    ans-=q;
                    cnt[i]--;
                }
            }
            if(i==3){
                while(cnt[i]>(n/2)){
                    int q=a3.top();
                    a3.pop();
                    ans-=q;
                    cnt[i]--;
                }
            }
            cout<<ans<<endl;
            return;
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        solve(n);
        while(!a1.empty())
            a1.pop();
        while(!a2.empty())
            a2.pop();
        while(!a3.empty())
            a3.pop();
        for(int i=1;i<=3;i++){
            cnt[i]=0;
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=0;
            }
        }
    }
    return 0;
}
