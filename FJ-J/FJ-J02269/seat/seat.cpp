#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1002];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	bool f=0;
	int cnt=0;
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(f==1)break;
		if(i%2==1){
			for(int j=1;j<=m;j++){
				cnt++;
				if(a[cnt]==ans){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				cnt++;
				if(a[cnt]==ans){
					cout<<i<<" "<<j;
					f=1;
					break;
				}
			}
		}
		
	}
	return 0;
} 
