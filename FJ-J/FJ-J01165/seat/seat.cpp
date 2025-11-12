#include<bits/stdc++.h>
using namespace std;
int n,m,r,s;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) s=i;
	}
	if(s%n==0){
		if(s/n%2==1){
			cout<<s/n<<" "<<n;
			return 0;
		}
		else{
			cout<<s/n<<" "<<1;
			return 0;
		}
	}
	else{
		if((s/n+1)%2==1){
			cout<<s/n+1<<" "<<s%n;
			return 0;
		}
		else{
			cout<<s/n+1<<" "<<n-s%n+1;
			return 0;
		}
	}
	return 0;
}
