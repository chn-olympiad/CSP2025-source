#include <bits/stdc++.h>
using namespace std;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1){
	    
		if(m==1&&n==1){
			cout<<1<<" "<<1;
			return 0;
		}
		for(int i=1;i<=m*n;i++){
			cin>>a[i];
		}
		int ans=a[1];
		
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<i;j++){
				if(a[i]>a[j])swap(a[i],a[j]);
			}
		}
		int ans1;
		for(int i=1;i<=m*n;i++){
			if(a[i]==ans) {
				ans1=i;
				break;
			}
		}
		cout<<ans1<<" "<<1;
		
	}
	return 0;
}
