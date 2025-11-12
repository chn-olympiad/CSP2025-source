#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e6+10;
int a[N],t;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;cin>>n;
    for(int i=0;i<n.size();i++){
        if(isdigit(n[i])) a[++t]=n[i]-'0';
    }
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=t;i++){
        cout<<a[i];
    }
    return 0;
}
