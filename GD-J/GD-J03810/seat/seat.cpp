#include<bits/stdc++.h>
using namespace std;
struct c1{
	long long n,a;
}a[100001]; 
bool cc(c1 a,c1 b){
	return a.a>b.a;
}
long long n,m,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].n=i;
		cin>>a[i].a;
	}
	sort(a+1,a+n*m+1,cc);
	for(int i=1;i<=n*m;i++){
		if(a[i].n==1){
			b=i;
			break;
		}
	}
	long long s=(b-1)/n+1;
	b=(b-1)%n;
	if(s%2==0){
		cout<<s<<' '<<n-b;
	}
	else{
		cout<<s<<' '<<b+1;
	}
	return 0;
}
