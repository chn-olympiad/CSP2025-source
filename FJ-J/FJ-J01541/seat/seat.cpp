#include<bits/stdc++.h> 
using namespace std; 
int n,m,a[105],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	if(r%n==0){
		cout<<r/n<<" ";
		if(r/n%2==0){
			cout<<1;
		}
		else cout<<n;
	}
	else{
		cout<<r/n+1<<" ";
		if((r/n+1)%2==0){
			cout<<(r/n+1)*n-r+1;
		}
		else cout<<n-((r/n+1)*n-r);
	}
	return 0; 
	
	
}
