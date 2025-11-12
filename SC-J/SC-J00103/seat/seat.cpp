#include<bits/stdc++.h>
using namespace std;
int n,m,R;
int a[101];
int findn(int s,int e){
	int mid=(s+e)/2;
	if(a[mid]==R||mid==e){
		return mid;
	}
	if(a[mid]>R){
		findn(s,mid);
	}else if(a[mid]<R){
		findn(mid+1,e);
	} 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}R=a[1];
	sort(a+1,a+m*n+1);
	int ans;
	ans=m*n+1-findn(1,m*n);
	if(ans%n!=0){
		if((ans/n+1)%2==0){
			cout<<ans/n+1<<" "<<n+1-ans%n;
		}else{
			cout<<ans/n+1<<" "<<ans%n;
		}
	}else{
		if((ans/n)%2==0){
			cout<<ans/n<<" "<<1;
		}else{
			cout<<ans/n<<" "<<n;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}