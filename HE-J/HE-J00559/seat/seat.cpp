#include<bits/stdc++.h>
using namespace std;

int a[20000];
long long n,m,k,c=1,r=1,R,p=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>n>>m;
	k=n*m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+k);
	for(long long i=n*m;i>=1;i--){
		if(a[i]==R){
			cout<<r<<' '<<c;
			break;
		}
		if(p==0){
			c++;
			if(c==n+1){
				c=n;
				r++;
				p=1;
			}
		}
		else{
			c--;
			if(c==0){
				c=1;
				r++;
				p=0;
			}
		}
	}
	return 0;
}
