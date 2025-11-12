#include<bits/stdc++.h>
using namespace std;
int b[1005];//shuzi
int n,m;
int ans;
bool cmp(int q,int h){
	return q>h;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	ans=b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==ans){
			ans=i;
		}
	}
	int x=0,jsq=0;
	while(1){
		x++;
		for(int i=1;i<=m;i++){
			jsq++;
			if(ans==jsq){
				cout<<x<<' '<<i; 
				return 0;
			}	
		}
		x++;
		for(int i=m;i>=1;i--){
			jsq++;
			if(ans==jsq){
				cout<<x<<' '<<i;
				return 0; 
			}
		}
	}
	return 0;
}