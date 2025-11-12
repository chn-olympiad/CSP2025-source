#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+(n*m)+1);
	int js=n*m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2!=0){
				if(a[js]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}else{
				if(a[js]==ans){
					cout<<i<<" "<<n-j+1<<endl;
					return 0;
				}
			}
			js--;
		}
	}
	
	return 0;
}
