#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,c,r;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int ans;
	for(int i=1;i<=n*m;i++){
		ans=a[1];
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}
		if(a[i]==ans){
			
		}
	}
	
	return 0;
}

