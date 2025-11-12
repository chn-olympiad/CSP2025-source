#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int t,n;
struct node{
    int lgst=0,del=0,maxa;
}st[maxn];
int fndbig(int x,int y,int z){
    if(x>y&&x>z) return 1;
    if(y>z) return 2;
    return 3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a[3];
            cin>>a[0]>>a[1]>>a[2];
            st[i].lgst=fndbig(a[0],a[1],a[2]);
            sort(a,a+3);
            st[i].del=a[2]-a[1],st[i].maxa=a[2];
        }
        priority_queue<int>q1,q2,q3;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            if(st[i].lgst==1){
                q1.push(-st[i].del);
                cnt1++;
            }
            if(st[i].lgst == 2){
                q2.push(-st[i].del);
                cnt2++;
            }
            if(st[i].lgst == 3){
                q3.push(-st[i].del);
                cnt3++;
            }
            ans+=st[i].maxa;
        }
        if(cnt1>n/2){
            int out=cnt1-n/2;
            for(int i=1;i<=out;i++){
                ans+=q1.top(); q1.pop();
            }
        } else if(cnt2>n/2){
            int out=cnt2-n/2;
            for (int i=1;i<=out;i++){
                ans+=q2.top(); q2.pop();
            }
        } else if(cnt3>n/2){
            int out=cnt3-n/2;
            for(int i=1;i<=out;i++){
                ans+=q3.top(); q3.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}