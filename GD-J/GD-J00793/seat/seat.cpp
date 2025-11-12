#include<bits/stdc++.h>
using namespace std;
bool pd(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n*m+1);
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	long long ans=a[1];
	sort(a.begin()+1,a.end(),pd);
	auto as=find(a.begin()+1,a.end(),ans)-a.begin();
	if(as%n==0){
		if(as/n%2==1){
			cout<<as/n<<" "<<n;
		}else{
			cout<<as/n<<" "<<1;
		}
	}else{
		if(as/n%2==0){
			cout<<as/n+1<<" "<<as%n;
		}else{
			cout<<as/n+1<<" "<<n-as%n+1;
		}
	}
	return 0;
}
