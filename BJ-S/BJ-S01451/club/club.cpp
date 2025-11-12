#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

struct member{
    int a[5];
    int d;
    bool operator < (const member x)const{
        return d>x.d;
    }
}a[maxn];

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
    }
    int sum=0;
    int cnt1=0,cnt2=0,cnt3=0;
    priority_queue<member> pq1,pq2,pq3;
    for(int i=1;i<=n;i++){
        if(a[i].a[1] >= a[i].a[2]  &&  a[i].a[1] >= a[i].a[3]){
            cnt1++;
            sum += a[i].a[1];
            a[i].d = min(abs(a[i].a[1]-a[i].a[2]),abs(a[i].a[1]-a[i].a[3]));
            pq1.push(a[i]);
        }
        else if(a[i].a[2] >= a[i].a[1]  &&  a[i].a[2] >= a[i].a[3]){
            cnt2++;
            sum += a[i].a[2];
            a[i].d = min(abs(a[i].a[2]-a[i].a[1]),abs(a[i].a[2]-a[i].a[3]));
            pq2.push(a[i]);
        }
        else{
            cnt3++;
            sum += a[i].a[3];
            a[i].d = min(abs(a[i].a[3]-a[i].a[1]),abs(a[i].a[3]-a[i].a[2]));
            pq3.push(a[i]);
        }
    }
    while(cnt1 > n/2){
        member now=pq1.top();
        pq1.pop();
        sum -= now.d;
        cnt1--;
    }
    while(cnt2 > n/2){
        member now=pq2.top();
        pq2.pop();
        sum -= now.d;
        cnt2--;
    }
    while(cnt3 > n/2){
        member now=pq3.top();
        pq3.pop();
        sum -= now.d;
        cnt3--;
    }
    cout<<sum<<endl;
    return;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int T=1;T<=t;T++){
        solve();
    }
    return 0;
}
