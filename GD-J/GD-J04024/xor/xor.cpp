#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int num[N];
int xo[N];
int ans;
int n,k;
void dfs(int l,int r,int len){
	if(r-l+1 < len) return ;
//	cout << "len: " << len << endl;
	for(int i=l+len-1;i<=r;i++){
//		cout << i << " " << i-len << endl; 
		if((xo[i]^xo[i-len]) == k){
			ans ++;
			dfs(l,i-len,len);
			dfs(i+1,r,len);
			return ;
		}
	}
	dfs(l,r,len+1);
}   
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		xo[i] = (xo[i-1] ^ num[i]);
	}
//	for(int i=1;i<=n;i++) cout << xo[i] << " "; cout << endl;
	dfs(1,n,1);
	cout << ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
