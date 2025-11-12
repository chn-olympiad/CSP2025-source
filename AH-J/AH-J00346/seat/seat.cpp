#include <bits/stdc++.h>
using namespace std;
long long a[1000000]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int RR=a[1];
	a[0]=111;
	for(int j=1;j<=n*m*n*m;j++){
		if(a[j]>a[j-1]){
			int d;
			d=a[j];
			a[j]=a[j-1];
			a[j-1]=d;
		}
	}
	if(a[1]==RR){
		cout<<1<<" "<<1;
		return 0;
	}
	int fin;
	for(int i=1;i<=n*m;i++){
		if(a[i]==RR){
			fin=i;
			break;
		}
	}
	if(((fin+n-1)/n)%2==0){
		cout<<(fin+n-1)/n<<" "<<n-fin%n+1;
	}else{
		cout<<(fin+n-1)/n<<" ";
		if(fin%n==0){
			cout<<n;
			return 0;
		}
		cout<<fin%n;
	}
	return 0;
}
