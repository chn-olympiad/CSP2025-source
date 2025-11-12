#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],b,k;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			k=i;
		}
	}
	cout<<k/n+1<<" ";
	if(k/n%2==0){
		cout<<k%n+1;
	}
	else{
		cout<<n-k%n;
	}
	return 0;
}