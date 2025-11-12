#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int xum[500010];
int c;
int memo[1001][1001];
int dfs(int l,int r){
    if(memo[l][r]!=0x3f3f3f3f){
        return memo[l][r];
    }
    int p;
    if(l>r){
        return 0;
    }
    if(l==r){
        if(a[l]==k){
            return 1;
        }else{
            return 0;
        }
    }
    int f=xum[r]^xum[l-1];
    if(f==k){
        p=1;
    }else{
        p=0;
    }
    int q=0;
    for(int i=l;i<r;i++){
        q=max(q,dfs(l,i)+dfs(i+1,r));
    }
    return memo[l][r]=max(q,p);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(memo,0x3f3f3f3f,sizeof(memo));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        xum[i]=xum[i-1]^a[i];
	}
	cout<<dfs(1,n);
	return 0;
}
