#include<bits/stdc++.h>
using namespace std;
struct Node{
	int s,cnt;
}a[200];
bool cmp(Node x,Node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].cnt=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].cnt==1){
			ans=i;
			break;
		}
	}
	cout<<(ans+n-1)/n<<" ";
	if((ans+n-1)/n%2==1){
		if(ans%n==0){
			cout<<n;
		}
		else{
		cout<<ans%n;
	}
	}
	else{
		if(ans%n==0){
			cout<<1;
		}
		else{
		cout<<n-ans%n+1;
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
