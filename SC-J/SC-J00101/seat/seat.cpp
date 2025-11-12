#include<bits/stdc++.h>
using namespace std;
int m,n,a[101],r,id;
bool cmp(int x,int y){
	return x>y;
}
void work(int x){
	int i=x/n,j=x%n;
	if(j==0){
		cout<<i<<" ";
		if(i%2==1)cout<<n<<"\n";
		else cout<<1<<"\n";
	}else{
		cout<<i+1<<" ";
		if((i+1)%2==1){ 
			cout<<j<<"\n";
		}
		else{
			cout<<n-j+1<<"\n";
		}
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	cin>>r;a[1]=r;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			id=i;
			break;
		}
	}
	work(id);
	return 0;
}