#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m,b;
pair<int,int> a[N],ans;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n * m;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a + 1,a + 1 + n * m,cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i].second == 1) b = i;
    }
    if(b % n == 0) ans.first = b / n;
    else ans.first = b % n;
    if(ans.first % 2 == 0) ans.second = n - b % n + 1;
    else ans.second = b % n;
    cout<<ans.first<<' '<<ans.second;
    return 0;
}
