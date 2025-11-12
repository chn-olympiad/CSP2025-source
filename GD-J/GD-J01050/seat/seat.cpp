#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[105]={};
int abc(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m>>r;
	arr[1]=r;
	for(int i=1;i<=m*n;i++){
		if(i!=1){
			cin>>arr[i];
		}
	}
	sort(arr+1,arr+m*n+1,abc);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			sort(arr+(i-1)*n+1,arr+i*n+1);
		}
	}
	for(int i=1;i<=m*n;i++){
		if(arr[i]==r){
			cout<<(i+1)/n<<" "<<i%n+1;
			return 0;
		}
	}
	return 0;
}
