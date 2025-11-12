#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1001],b[101][101],w=0,q=0,e=0;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			w=n*m-i+1;
			break;
		}
	}
	q=w/n;
	e=w%n;
	if(q==0||q==1&&w==n){
		cout<<'1'<<' '<<w;
		return 0;
	}
	else if((q+1)%2==0){
		cout<<q+1<<' '<<n-e+1;
		return 0;
	}
	else{
    	cout<<q+1<<' '<<e;
		return 0;
	}
	return 0;
}