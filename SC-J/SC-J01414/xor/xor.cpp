#include<bits/stdc++.h>
using namespace std;
struct aox{
	int l,r;
};
int n,k,a[500001];
aox vis[500001];
int check(int start,int end){
	int x=a[start];
	for(int i=start+1;i<=end;i++){
		x=x^a[i];
	}
	return x;
}
int main(){
	//记得干掉注释; 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j,w=0;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			int x=check(i,j);
			if(x==k){
				vis[w].l=i;
				vis[w].r=j;
				w++;
			}
		}
	}
	if(w==0){
		cout<<0;
		return 0;
	}
	sort(vis,vis+w,[](aox x,aox y){
		return x.r<y.r;
	});
	int start=vis[0].r,cnt=1;
	for(i=1;i<w;i++){
		if(vis[i].l>start){
			start=vis[i].r;
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 