#include<bits/stdc++.h>
using namespace std;
int a[105];

int t,w,l,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(t>a[i]){
			w++;
		}
		else break;
	}
	f=m*n-w;
	l=(f/(m+1)+1)*m;
	
	
	cout<<f/(m+1)+1;
	cout<<" ";
	cout<<(f-l)%(m+1);
	return 0;
}
