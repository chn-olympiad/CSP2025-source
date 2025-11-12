#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,a[N][5],cnt[5],ans,b[N],pos[N];
void work(){
    ans=0;
    cnt[1]=cnt[2]=cnt[3]=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
            pos[i]=1;
            cnt[1]++;
            ans += a[i][1];
        }else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
            pos[i]=2;
            cnt[2]++;
            ans += a[i][2];
        }else {
            pos[i]=3;
            cnt[3]++;
            ans += a[i][3];
        }
    }
    vector<int>arr;
    if (cnt[1] > n / 2) {
        for (int i = 1; i <= n; ++i) {
            if(pos[i] == 1)
                arr.push_back(min(a[i][1] - a[i][2], a[i][1] - a[i][3]));
        }
        int top=0;
        sort(arr.begin(),arr.end());
        for(int i=cnt[1];i>n/2;--i) {
            ans-=arr[top++];
        }
    }else if (cnt[2] > n / 2) {
        for (int i = 1; i <= n; ++i) {
            if(pos[i] == 2)
                arr.push_back(min(a[i][2] - a[i][1], a[i][2] - a[i][3]));
        }
        int top=0;
        sort(arr.begin(),arr.end());
        for(int i=cnt[2];i>n/2;--i) {
            ans-=arr[top++];
        }
    }else if (cnt[3] > n / 2) {
        for (int i = 1; i <= n; ++i) {
            if(pos[i] == 3)
                arr.push_back(min(a[i][3] - a[i][1], a[i][3] - a[i][2]));
        }
        int top=0;
        sort(arr.begin(),arr.end());
        for(int i=cnt[3];i>n/2;--i) {
            ans-=arr[top++];
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int Case;
    cin>>Case;
    while(Case--){
        work();
    }
    return 0;
}
// g++ /home/noi/Desktop/TTY/club.cpp -o club -O2 -std=c++14 -static

/*
According to n%2==0
So there is only one that over n/2
And there will be OK after moving the ones which more than n/2

*/

/*
record:
about 00:40
    overcome all big example, believe that it is OK
    VScode is so comfortable and convinent

How bad my English is!
*/