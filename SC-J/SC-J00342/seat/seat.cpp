#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int sr=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sr){
			sr=i;
		}
	}
	int k=sr/n;
	int b=sr%n;
	if(b==0){
		cout<<k<<" ";
		if(k&1){
			cout<<n<<" ";
			return 0;
		}else{
			cout<<1<<" ";
			return 0;
		}
	}else{
		cout<<k+1<<" ";
		if(k&1){
			cout<<n-b+1<<" ";
			return 0;
		}else{
			cout<<b<<" ";
			return 0;
		}
	}
	return 0;
}