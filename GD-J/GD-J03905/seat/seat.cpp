#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long s[n*m+1],r;
	memset(s,0,sizeof(s));
	for(long long i=1;i<=n*m;i++){
		cin>>s[i];
	}
	r=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(s[i]==r){
			if(i%n==0){
				if(i/n%2==0){
					cout<<i/n<<' '<<1;
				}
				else{
					cout<<i/n<<' '<<n;
				}
			}
			else{
				if((i+n)/n%2==0){
					cout<<(i+n)/n<<' '<<n-i%n+1;
				}
				else{
					cout<<(i+n)/n<<' '<<i%n;
				}
			}
		}
	}
	return 0;
}
