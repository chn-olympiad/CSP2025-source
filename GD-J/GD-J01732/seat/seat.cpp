#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b,p,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			p=n*m-i+1;
			break;
		}
	}
	s=p/n;
//	cout<<s<<" "<<p<<endl;
	if(p%n==0){
		if(s%2==1)cout<<s<<" "<<n;
		else cout<<s<<" "<<1;
	}
	else if(s%2==0)cout<<s+1<<" "<<p%n;
	else cout<<s+1<<" "<<n-p%n+1;
	return 0;
}
