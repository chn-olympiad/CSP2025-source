#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int s;
	for(int i=1;i<=n*m;i++){
		if(ans==a[i]){
			s=i;
			break;
		}
	}
	int l=(s+n-1)/n;
	cout<<l<<" ";
	if(l%2==0){
		cout<<n-l%n;
	}
	else{
		cout<<s-(l-1)*n;
	}
	return 0;
} 
