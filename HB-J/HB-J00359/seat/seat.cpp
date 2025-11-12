#include <bits/stdc++.h>
using namespace std;
int a[150],sum,ans,j,k=1,f=1,n,m;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		}
		ans=a[1];
		sort(a+1,a+n*m+1);
		for(int i=n*m;i>=1;i--){
			j++;
				if(a[i]==ans){
					sum=j;
				}
		}
		for(int i=2;i<=sum;i++){
			if(f==n&&k%2==1){
				k++;
				}
			else if(f==1&&k%2==0){
					k++;
			}else{
					if(k%2==0&&f>1){
						f--;
					}
					if(k%2==1&&f<n){
						f++;
					}
			
			}
		}
		cout<<k<<" "<<f;
	return 0;
}
