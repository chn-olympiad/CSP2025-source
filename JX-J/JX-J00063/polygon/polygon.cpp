#include<bits/stdc++.h>
#define ll long long
#define N 10000010
#define M 1010
using namespace std;
ll n,a[N],b[N],d,s;
void dfs(ll t){
    if(t==n+1){
        ll y=0,f=0;
        for(int i=1;i<=d;i++){
            y+=b[i];
            f=max(f,b[i]);
        }
        if(d>=3&&y>2*f){
            ++s;
        }
        return;
    }
    b[++d]=a[t];
    dfs(t+1);
    b[d]=0;
    --d;
    dfs(t+1);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	dfs(1ll);
	cout<<s<<endl;
    return 0;
}
