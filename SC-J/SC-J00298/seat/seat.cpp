#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,t1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			t1=i;break;
		}
	}
	if(t1%n==0) cout<<t1/n<<" "<<n;
	else{
		cout<<t1/n+1<<" ";
		if((t1/n)%2==0) cout<<t1%n;
		else cout<<n-(t1%n)+1;
	}
	return 0;
} 