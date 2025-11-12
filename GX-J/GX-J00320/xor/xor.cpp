#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int n,k,a[N],ans;
struct node{
    int x,y;
};
vector<node>v;
bool cmp(node A,node B){
    return A.y<B.y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int cnt=a[i];
        if(cnt==k){
            node temp;
            temp.x=i;
            temp.y=i;
            v.push_back(temp);
        }
        for(int j=i+1;j<=n;j++){
            cnt=cnt^a[j];
            if(cnt==k){
                node temp;
                temp.x=i;
                temp.y=j;
                v.push_back(temp);
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    if(v.size()==0){
        cout<<0;
        return 0;
    }
    ans++;
    int j=0;
    for(int i=1;i<v.size();i++){
        if(v[i].x>v[j].y){
            ans++;
            j=i;
        }
    }
    cout<<ans;
    return 0;
}
