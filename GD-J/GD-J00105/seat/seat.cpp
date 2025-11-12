#include <iostream>
#include <algorithm>
using namespace std;
int n,m,ans,a[111];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(a[i*n+1]<ans and a[(i-1)*n+1]>=ans){
			if((i+1)%2==0){
				for(int s=1;s<=n;s++){
					if(a[(i-1)*n+s]==ans){
						cout<<i<<' '<<s;
					}
				}
			}else{
				for(int s=1;s<=n;s++){
					if(a[(i-1)*n+s]==ans){
						cout<<i<<' '<<n+1-s;
					}
				}
			}
		}
	}
	return 0;
}
