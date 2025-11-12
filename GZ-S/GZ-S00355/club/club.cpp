// GZ-S00355 程袁浩 华师一 
#include <bits/stdc++.h>
#define int long long
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define PII pair<int,int>
using namespace std;
const int N=1e5+10;
int a[N][3],b[N][3],gg[N];
int n;
void solve() {
    cin>>n;
    upp(i,1,n) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        tie(b[i][0],b[i][1],b[i][2])=make_tuple(a[i][0],a[i][1],a[i][2]);
        sort(b[i],b[i]+3);
        reverse(b[i],b[i]+3);
    }
    int ans=0,d1=0,d2=0,d3=0;
    upp(i,1,n) {
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) d1++,ans+=a[i][0],gg[i]=1;
        else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) d2++,ans+=a[i][1],gg[i]=2;
        else d3++,ans+=a[i][2],gg[i]=3;
    }
    //cout<<"&&"<<ans<<endl;
    if(d1>n/2) {
        vector<int> vec;
        upp(i,1,n) {
            if(gg[i]==1) vec.pb(b[i][1]-b[i][0]);
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        upp(i,0,d1-n/2-1) {
        	//cout<<"!!"<<vec[i]<<endl;
            ans+=vec[i];
        }
    }
    else if(d2>n/2) {
        vector<int> vec;
        upp(i,1,n) {
            if(gg[i]==2) vec.pb(b[i][1]-b[i][0]);
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        upp(i,0,d2-n/2-1) {
            ans+=vec[i];
        }
    }
    else if(d3>n/2) {
        vector<int> vec;
        upp(i,1,n) {
            if(gg[i]==3) vec.pb(b[i][1]-b[i][0]);
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        upp(i,0,d3-n/2-1) {
            ans+=vec[i];
        }
    }
    cout<<ans<<endl;
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int tt;cin>>tt;
    while(tt--) solve();
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/ 
