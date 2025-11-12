#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,ans;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >cnt1,cnt2,cnt3;
struct node{
    int x,y,z;
}a[N];
int get_min(node x){
    return min(x.x,min(x.y,x.z));
}
int get_max(node x){
    return max(x.x,max(x.y,x.z));
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
  cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            int cnt=get_min(a[i]);
            a[i].x-=cnt;
            a[i].y-=cnt;
            a[i].z-=cnt;
            ans+=cnt;
        }
        for(int i=1;i<=n;i++){
            if(a[i].x==a[i].y&&a[i].x==a[i].z) continue;
            else if(a[i].x>a[i].y&&a[i].x>a[i].z){
                if(cnt1.size()<n/2) cnt1.push(make_pair(a[i].x-max(a[i].y,a[i].z),i));
                else if((a[i].x-max(a[i].y,a[i].z))>cnt1.top().first){
                    pair<int,int>x=cnt1.top();
                    cnt1.pop();
                    cnt1.push(make_pair(a[i].x-max(a[i].y,a[i].z),i));
                    ans+=max(a[x.second].y,a[x.second].z);
                }
                else{
                    ans+=max(a[i].y,a[i].z);
                }
            }
            else if(a[i].y>a[i].x&&a[i].y>a[i].z){
                if(cnt2.size()<n/2){
                    cnt2.push(make_pair(a[i].y-max(a[i].x,a[i].z),i));
                }
                else if((a[i].y-max(a[i].x,a[i].z))>cnt2.top().first){
                    pair<int,int>x=cnt2.top();
                    cnt2.pop();
                    cnt2.push(make_pair(a[i].y-max(a[i].x,a[i].z),i));
                    ans+=max(a[x.second].x,a[x.second].z);
                }
                else{
                    ans+=max(a[i].x,a[i].z);
                }
            }
            else if(a[i].z>a[i].y&&a[i].z>a[i].x){
                if(cnt3.size()<n/2) cnt3.push(make_pair(a[i].z-max(a[i].y,a[i].x),i));
                else if((a[i].z-max(a[i].y,a[i].x))>cnt3.top().first){
                    pair<int,int>x=cnt3.top();
                    cnt3.pop();
                    cnt3.push(make_pair(a[i].z-max(a[i].y,a[i].x),i));
                    ans+=max(a[x.second].x,a[x.second].y);
                }
                else{
                    ans+=max(a[i].x,a[i].y);
                }
            }
            else{
                ans+=get_max(a[i]);
            }
        }
        while(!cnt1.empty()){
            pair<int,int>x=cnt1.top();
            ans+=a[x.second].x;
            cnt1.pop();
        }
        while(!cnt2.empty()){
            pair<int,int>x=cnt2.top();
            ans+=a[x.second].y;
            cnt2.pop();
        }
        while(!cnt3.empty()){
            pair<int,int>x=cnt3.top();
            ans+=a[x.second].z;
            cnt3.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}