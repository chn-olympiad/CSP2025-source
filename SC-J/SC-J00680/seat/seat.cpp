#include<bits/stdc++.h>
using namespace std;
int a[111];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<"a["<<i<<"]-------------------------->"<<a[i]<<"\n";
//	}
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ans=i;
		}
	}
	if((ans/n+1)%2==0 && ans%n!=0){
		if(ans%m==0){
			cout<<ans/n<<" 1";
		}
		else{
			cout<<ans/n+1<<" "<<(m-ans%m)+1;
		}
	}
	else{
		if(ans%m==0){
			cout<<ans/n<<" "<<m;
		}
		else{
			cout<<ans/n+1<<" "<<ans%m;
		}
	}
	return 0;
}