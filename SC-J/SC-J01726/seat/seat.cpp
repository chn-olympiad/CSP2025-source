#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int t=m*n;
	int a[t];
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	int ans=a[0],count=0;
	sort(a,a+t,greater<int>());
	for(int i=0;i<t;i++){
		if(a[i]==ans){
			count=i+1;
			break;
		}
	}
	int k=int(int((count*1.0/m)-0.01))+1;
	cout<<k<<' ';
	if(k%2)cout<<m-(k*m-count);
	else cout<<((k*m)-count)+1;
	return 0;
}