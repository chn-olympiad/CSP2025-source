#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int T,n,a[N][4],b[N],ans;
int v[101][101][101];
void dfs(int i,int cnt1,int cnt2,int cnt3,int tot){
	if(i>n){
		ans=max(ans,tot);
		return;
	}
	if(v[cnt1][cnt2][cnt3]>=tot) return;
//	printf("%d [%d %d %d]=%d\n",i,cnt1,cnt2,cnt3,tot);
	if(cnt1+1<=n/2) dfs(i+1,cnt1+1,cnt2,cnt3,tot+a[i][1]);
	if(cnt2+1<=n/2) dfs(i+1,cnt1,cnt2+1,cnt3,tot+a[i][2]);
	if(cnt3+1<=n/2) dfs(i+1,cnt1,cnt2,cnt3+1,tot+a[i][3]);
	return;
}
void worksmall(){
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
	return;
}
void workA(){
	for(int i=1;i<=n;i++) b[i]=a[i][1];
	sort(b+1,b+n+1);
	for(int i=n;i>n/2;i--) ans+=b[i];
	cout<<ans;
	return;
}
void workB(){
	for(int i=1;i<=n;i++){
		
		
	}
	return;
}
void clear(){
	ans=0;
	memset(v,-1,sizeof v);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		clear();
		bool A=1,B=1,C=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]!=0){
					if(A&&j==2) A=0;
					if(B&&j==3) A=B=0;
				}
			}
		}
		if(A){
			workA();
		}
//		else if(B){
//			workB();
//		}
		else if(n<=30){
			worksmall();
		}
	}
	
	return 0;
} 
