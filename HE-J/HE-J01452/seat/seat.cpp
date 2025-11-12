#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],f;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	
	f=a[1];
	sort(a+1,a+n*m+1,cmp);	
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
			break;
		}
	}
	if(f%n!=0){
		if((f/n)%2==0) cout<<f/n+1<<" "<<f%n;
		else cout<<f/n+1<<" "<<n-f%n+1; 
	}
	else{
		if((f/n)%2==0) cout<<f/n<<" "<<1;
		else cout<<f/n<<" "<<n;
	}
	
	
	return 0;
}
