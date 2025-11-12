#include<bits/stdc++.h>
using namespace std;
const long long N=110;
long long n,m;
struct S{
	long long f;
	bool R;
}arr[N];
bool cmp(S a,S b){
	return a.f>b.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m;
	arr[1].R=true;
	for(long long i=1;i<=n*m;i++){
		cin>>arr[i].f;
	}
	sort(arr+1,arr+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(arr[i].R==true){
			if(i%n==0)cout<<i/n<<' ';
			if(i%n)cout<<i/n+1<<' ';
			if(i%n==0){
				cout<<n;
				return 0;
			}
			if((i/n)%2){
				cout<<n-i%n+1;
				return 0;
			}
			cout<<i%n;
			return 0;
		}
	}
	return 0;
}