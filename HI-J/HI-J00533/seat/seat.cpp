#include<bits/stdc++.h>
using namespace std;
int a[105];
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
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int p;
	int ans1=1,ans2=1;

	for(int i=1;i<=n*m;i++){

		if(a[i]==k){
	
	p=i;
		}
	}
	ans1=p/n;

ans2=p%n;

if(ans2!=0){
	ans1++;

}
if(ans1%2==1){
	if(ans2==0){
		cout<<ans1<<" "<<n;
	}else{
		cout<<ans1<<" "<<ans2;
	}
	
}else{
	if(ans2==0){
		cout<<ans1<<" "<<1;
	}else{
		cout<<ans1<<" "<<n-ans2+1;
	}
	
}
	return 0; 
}
