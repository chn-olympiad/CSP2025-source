#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int v1,v2,v3;
    int mx,id;
    int mx1,mx2,mx3;
}a[N];
bool cmp(node a,node b){
    if(max({a.v1-a.mx1,a.v2-a.mx2,a.v3-a.mx3})==max({b.v1-b.mx1,b.v2-b.mx2,b.v3-b.mx3}))return a.mx>b.mx;
    return max({a.v1-a.mx1,a.v2-a.mx2,a.v3-a.mx3})>max({b.v1-b.mx1,b.v2-b.mx2,b.v3-b.mx3});
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].v1>>a[i].v2>>a[i].v3;
    for(int i=1;i<=n;i++){
        a[i].mx=max(max(a[i].v1,a[i].v2),a[i].v3);
        a[i].mx1=max(a[i].v2,a[i].v3);
        a[i].mx2=max(a[i].v1,a[i].v3);
        a[i].mx3=max(a[i].v1,a[i].v2);
    }
    sort(a+1,a+n+1,cmp);
    int cnt1=0,cnt2=0,cnt3=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].v1==a[i].mx){
            if(cnt1>=n/2){
                if(a[i].mx1==a[i].v2 && cnt2<n/2)cnt2++,ans+=a[i].v2;
                else cnt3++,ans+=a[i].v3;
            }else {
                cnt1++;
                ans+=a[i].mx;
            }
        }
        else if(a[i].v2==a[i].mx){
            if(cnt2>=n/2){
                if(a[i].mx2==a[i].v1 && cnt1<n/2)cnt1++,ans+=a[i].v1;
                else cnt3++,ans+=a[i].v3;
            }else {
                cnt2++;
                ans+=a[i].mx;
            }   
        }
        else if(a[i].v3==a[i].mx){
            if(cnt3>=n/2){
                if(a[i].mx3==a[i].v2 && cnt2<n/2)cnt2++,ans+=a[i].v2;
                else cnt1++,ans+=a[i].v1;
            }else {
                cnt3++;
                ans+=a[i].mx;
            }   
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
