#include <iostream>
using namespace std;
int main (){
	int m,n,a[999],l,ans;
	cin >>n>>m;
	for(int i=0;i<m*n;i++)cin>>a[i];
	int q=a[0];
	for (int k=0;k<m*n-1;k++){
		for (int j=k+1;j<m*n;j++){
			if (a[j]>a[k]){
				int c=a[j];
				a[j]=a[k];
				a[k]=c;
			}
		}
	}
	for (l=0;l<m*n;l++){
		if (a[l]==q)break;
	}
	int r=(l+1)/n+1,t=(l+1)%n;
	if (t==0){
		t=n;
		r=r-1;
	}
	if (r%n==0){
		int ans=n-t+1;
	}else{
		ans=t;
	}
	cout<<r<<" "<<ans;
	return 0;
}
