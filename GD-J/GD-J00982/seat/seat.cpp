#include<bits/stdc++.h>
using namespace std;
int a[107],b[107];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,greater<int>());
	int in;
	for(int i=1;i<=n*m;i++){
		if(a[1]==b[i]){
			in=i;
		}
	}
//	cout<<in<<endl;
	int l=in/n+(in%n!=0);
	cout<<l<<" ";
//	cout<<in<<endl;
	if(l%2==1){
		if(in%n==0)cout<<n;
		else cout<<in%n;
	}
	else{
		cout<<n-in%n+1;
	}
	return 0;
}

