#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];//n log n
int sum[500005];
/*
bool check(int x){
	//judge the num >= x
	int cnt=0;
	int r=1;
	for(int l=1; l<=n; l++){
		r=l;
		while((sum[r]^sum[l-1])!=k && r<=n) r++;
		if((sum[r]^sum[l-1])==k){
			cnt++;
			l=r;
			continue;
		}
	}
	return cnt>=x;
}*/
int vis[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int cnt=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i], sum[i]=sum[i-1]^a[i];
	if(k==0){
	    for(int i=1; i<=n; i++){
		    if(a[i]>0 && a[i-1]>0 && a[i]==a[i-1] && vis[i]==0 && vis[i-1]==0)  
		        cnt++, vis[i]=1, vis[i-1]=1;
		    if(a[i]==0) cnt++;
		}	
	}
	else if(k==1){
	    for(int i=1; i<=n; i++) if(a[i]==1) cnt++;	
	}
	cout<<cnt;
	return 0;
}
