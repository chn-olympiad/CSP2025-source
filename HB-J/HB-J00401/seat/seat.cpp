#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+x);
	int k1;
	for(int i=1;i<=x;i++){
		if(a[i]==k){
			k1=i;
			break;
		}
	}
	int k2=x-k1+1;
	if((k2%n)>=1){
		cout<<k2/n+1<<" ";
		if((k2/n+1)%2==1){
			cout<<k2%n;
		}
		else{
			cout<<n-k2/n+1;
		}
	}
	else{
		cout<<k2/n<<" ";
		if((k2/n+1)%2==1){
			cout<<k2%n;
		}
		else{
			cout<<n-k2/n+1;
		}
	}
	return 0;
}
