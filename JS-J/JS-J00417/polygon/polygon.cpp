#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct node{
    int num,cnt;
};
int a[10000];
vector<node> fg;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    fg.push_back((node){a[1],1});
    for(int i=2;i<=n;i++){
        int siz=fg.size();
       for(int j=0;j<siz;j++){
           if(fg[j].cnt>=2){
               if(fg[j].num>a[i]){
                   ans++;
                   ans%=998244353;
               }
         }
            fg.push_back((node){fg[j].num+a[i],fg[j].cnt+1});
        }
        fg.push_back((node){a[i],1});
    }
cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}


