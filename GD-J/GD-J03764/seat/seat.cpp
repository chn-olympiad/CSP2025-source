#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],ind;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ind=i;
		}
	}
	if(ind%n==0){
		if(ind/n%2==0){
			cout<<ind/n<<" "<<1;
		}
		else{
			cout<<ind/n<<" "<<n;
		}
		return 0;
	}
	int x=ind/n;
	cout<<x+1<<" ";
	if(x%2==0){
		cout<<ind%n;
	}
	else{
		cout<<m+1-x%n;
	}
	return 0; 
}
