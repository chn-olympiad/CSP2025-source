#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
	} 
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(s==a[i]){
			s=n*m-i+1;
			break;
		}
		//cout<<a[i]<<' ';
	}
	//cout<<s<<endl;
	if(s/n+1%2==0){
		l=n-s%n;
	}else{
		l=s%n;
	}
	cout<<s/n+1<<' '<<l;
}
