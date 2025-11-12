#include<bits/stdc++.h>
using namespace std;
int n,m,p,t;
int a[1024];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		scanf("%d",&a[i]);
	}
	t=a[1];
	sort(a+1,a+x+1);
	for(int i=1;i<=x;i++){
		if(a[i]==t){
			p=x-i+1;
			break;
		}
	}
	int l;
	if(p%n==0){
		cout<<p/n<<" "<<n;
		return 0;
	}else{
		l=p/n+1;
	}
	cout<<l<<" ";
	if(l%2==0){
		cout<<n-p%n+1;
	}else{
		cout<<p%n;
	}
	return 0;
}
