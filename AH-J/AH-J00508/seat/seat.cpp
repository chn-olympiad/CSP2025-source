#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(const int x,const int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,ans,mc;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			mc=i;
			break;
		}
	}
	if(mc%n==0){
		if(mc/n%2==0){
			cout<<mc/n<<" "<<"1";
		}
		else{
			cout<<mc/n<<" "<<n;
		}
	}
	else{
		cout<<mc/n+1<<" ";
		if((mc/n+1)%2==0){
			cout<<n-(mc%n)+1;
		}
		else{
			cout<<mc%n;
		}
	}
	return 0;
}
