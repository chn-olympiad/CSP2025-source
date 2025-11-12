#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,r,cnt,ans1,ans2;
struct node{
	int x,id;
}a[10005];
int k[105][105];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			r=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k[j][i]=++cnt;
			}
		}else{
			for(int j=n;j>=1;j--){
				k[j][i]=++cnt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<k[i][j]<<" ";
			if(k[i][j]==r){
				ans1=i;ans2=j;
			}
		}
//		cout<<"\n";
	}
	cout<<ans2<<" "<<ans1;
	return 0;
} 
