#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1,j=n*m;i<=n*m;i++,j--){
		if(a[i]==x){
			if(((j+n-1)/n)%2==1){
				cout<<(j+n-1)/n<<" ";
				if(j%n==0){
					cout<<n;
				}else{
					cout<<j%n;
				}
			}else{
				cout<<(j+n-1)/n<<" "<<n-j%n+1;
			}
			break;
		}
	}
	return 0;
}
