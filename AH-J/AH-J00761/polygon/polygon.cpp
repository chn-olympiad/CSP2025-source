#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt;
int a[5005];
bool k;
void dfs(int k,bool f,int p,int l){
    //cout<<k<<" "<<f<<" "<<p<<" "<<l<<endl;
    if(k==n){
        if(p>l*2&&l>=3){
            cnt++;
			//cout<<k<<" "<<f<<" "<<p<<" "<<l<<endl;
        }
        return;
    }
    dfs(k+1,1,p+a[k+1],a[k+1]);
    dfs(k+1,0,p,l);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
			k=1;
		}
    }
    if(!k){
		cout<<n-2;
		return 0;
	}
    sort(a+1,a+1+n);
    dfs(0,1,0,0);
    cout<<cnt;
    return 0;
}
