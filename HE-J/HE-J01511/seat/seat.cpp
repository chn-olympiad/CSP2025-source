#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int x=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) x++;
	}
	if(x==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(x%n==0){
		cout<<x/n<<" ";
		if((x/n)%2==0) cout<<1;
		else cout<<n;
	}
	else{
		cout<<x/n+1<<" ";
		if((x/n+1)%2==0){
			cout<<n-(x%n-1);
		}
		else{
			cout<<x%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
