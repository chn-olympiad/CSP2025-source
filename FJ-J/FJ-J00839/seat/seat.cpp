#include<bits/stdc++.h>
using namespace std;

int n,m,a[122],c,e,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			e=a[i];
		}
		if(i!=1){
			for(int j=i;j>=2;j--){
				c=a[j]+a[j-1];
				a[j-1]=max(a[j],a[j-1]);
				a[j]=c-a[j-1];
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==e){
			x=i;
		}
	}
	if(x%n==0){
		if(x%(2*n)==0){
			cout<<x/n<<' '<<1;
		}else{
			cout<<x/n<<' '<<n;
		}
	}else if(x%(2*n)<n){
		cout<<x/n+1<<' '<<x%n;
	}else{
		cout<<x/n+1<<' '<<n-x%n+1;
	}
	return 0;
}
