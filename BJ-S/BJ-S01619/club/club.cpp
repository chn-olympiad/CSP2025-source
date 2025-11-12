#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct member{
    int a1,a2,a3;
    int sum(){
        return a1+a2+a3;
    }
    int mx(){
        return max({a1,a2,a3});
    }
    int cmx(){
        return min({max(a1,a2),max(a1,a3),max(a2,a3)});
    }
    int mn(){
        return min({a1,a2,a3});
    }
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<member> a(n+1);
    vector<vector<member>> choose(4);
    int cnt[4]={0,0,0,0};
    for(int i=1;i<=n;i++)cin>>a[i].a1>>a[i].a2>>a[i].a3;
    sort(a.begin()+1,a.end(),[](member x,member y){
        if(x.sum()!=y.sum())return x.sum()<y.sum();
        else return x.mx()<y.mx();
    });
    int sum=0;
    for(int i=1;i<=n;i++){
        int mxn=a[i].mx();
        int mxpos;
        if(a[i].a1==mxn)mxpos=1;
        if(a[i].a2==mxn)mxpos=2;
        if(a[i].a3==mxn)mxpos=3;
        sum+=mxn;
        cnt[mxpos]++;
        choose[mxpos].push_back(a[i]);
    }
    int over=0;
    if(cnt[1]>n/2)over=1;
    if(cnt[2]>n/2)over=2;
    if(cnt[3]>n/2)over=3;
    if(over){
        sort(choose[over].begin(),choose[over].end(),[](member x,member y){return (x.mx()-x.cmx())<(y.mx()-y.cmx());});
        for(int i=0;i<cnt[over]-n/2;i++){
            sum-=(choose[over][i].mx()-choose[over][i].cmx());
        }
    }
    cout<<sum<<'\n';
}
    return 0;
}
