#include<bits/stdc++.h>
using namespace std;
int a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m,ans;
	for(int i=1;i<=s;i++)cin>>a[i];
	ans=a[1];
	sort(a+1,a+s+1);
	for(int i=1,j=s;i<j;i++,j--)swap(a[i],a[j]);
	for(int i=1;i<=s;i++)if(a[i]==ans)ans=i;
	if(ans<=n){
		cout<<"1"<<" "<<ans;
		return 0;
	}
	else {
		for(int x=1;x<=10;x++){
			if(x%2==0){
				if(ans>x*n&&ans<=(x+1)*n){
					cout<<x+1<<" "<<ans-x*n;
					return 0;
				}
			}
			if(x%2!=0){
				if(ans>x*n&&ans<=(x+1)*n){
					cout<<x+1<<" "<<(x+1)*n-ans+1;
					return 0;
				}
			}
		}
	}
}
