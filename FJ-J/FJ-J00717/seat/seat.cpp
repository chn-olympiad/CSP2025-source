#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,c,k;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];	
	}
	c=a[0];
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++){
		if(a[i]==c){
			k=i;
			break;
		}
	}
	cout<<k/n+1<<' ';
	if(k/n%2==1){
		cout<<n-(k-k/n*n);
	}
	else cout<<k-k/n*n+1;
}
