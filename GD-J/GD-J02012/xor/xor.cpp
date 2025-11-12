#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct D{
	int l;
	int r;
}d[N];
int dfs(int i,int ans,int c){
	for(int j=i;j<c;j++){
		if(d[i].l==d[j].l or d[i].r>=d[j].l) continue;
		else ans=max(ans+1,dfs(j,ans+1,c));
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[N];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int xd;
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(i==j) xd=a[i]^a[i];
			else{
				xd=a[i];
				for(int z=i+1;z<=j;z++){
					xd=a[z]^xd;
				}
			}
			if(xd==k){
				d[c].l=i;
				d[c].r=j;
				c++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	if(c==0){
		cout<<0;
		return 0;
	}
	int ans = 0;
	ans=max(ans+1,dfs(0,1,c));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
