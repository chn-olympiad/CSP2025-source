#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[1005],q,s,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		b[i]=a[n*m-i+1];
		if(b[i]==q){
			s=i;
			break;
		}
	}
	if(s%n!=0){
		cout<<s/n+1<<" ";
		p=s/n+1;
	}
	else{
		cout<<s/n<<" ";
		p=s/n;
	}
	if(p%2!=0){
		if(s%m!=0) cout<<s%m;
		else cout<<m;
	}
	else{
		if(s%m!=0) cout<<m-(s%m)+1;
		else cout<<1;
	}
	return 0;
}
