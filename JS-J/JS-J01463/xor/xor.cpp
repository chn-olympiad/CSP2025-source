#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n,m;
struct len{
    int l,r;
}b[100010];
bool judge(int l,int r){
    int x=0;
    for(int i=l;i<=r;i++){
            x=0;
        int aa=x,bb=a[i];
        while(aa>0||bb>0){
            x=x*2+(aa%2!=bb%2);
        }
    }
    if(x==m){
        return true;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    cin>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        for(int j=j;j<=n;j++){
            if(judge(i,j))b[cnt++].l=i,b[cnt].r=j;
        }
    }
    cout<<cnt;
    return 0;
}
