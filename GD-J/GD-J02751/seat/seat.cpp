#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[205],s[20][20],ans;

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++) cin>>a[i];
	
	ans=a[1];
	
	sort(a+1,a+1+(n*m),cmp);
	
	int o=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=a[++o];
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				s[j][i]=a[++o];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==ans){
				cout<<j<<" "<<i;
				
				return 0;
			}
		}
	}	
	
	return 0;
}
