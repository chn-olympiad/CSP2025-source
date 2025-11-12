#include<bits/stdc++.h>
using namespace std;

int const N = 5e5+10;
int a[N];
int n,k,cnt = 0;

bool check(int x,int y){
	int sum = 0;
	sum = a[x];
	for(int i = x+1;i<y;i++){
		sum = sum^a[i];
	}
	if(sum == k){
		return true;
	}
	
	return false;
}


void dfs(int l,int r){
	if(l > r){
		return;
	}
	
	
	for(int i = l;i<=r;i++){
		for(int j = i;j<=r;j++){
			if(check(i,j)){
				cnt++;
				dfs(j+1,r);
			}
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	
	dfs(1,n);
	cout<<cnt;
	return 0;
}
