#include<bits/stdc++.h>
using namespace std;
long long a[110];
bool cmp(const long long &x,const long long &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n,m;
	cin>>n>>m;
	int f=0;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
		}
	}
	if(f%n==0) cout<<f/n<<" "<<n;
	else cout<<f/n+1<<" "<<f%n;
	
	return 0;
} 
