#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100100],b,c;
int32_t main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);std::cout.tie(nullptr);
	std::cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	for(int i=1;i<n*m;i++){
		for(int j=0;j<n*m-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(b==a[i]){
			c=i+1;
			break;
		}
	}
	for(int i=0;i<m;i++){
		int a=i+1;
		if(c<=n*a){
			std::cout<<a<<" ";
			break;
		}
	}
	for(int i=0;i<n*m;i++){
		int a=i+1;
		if(c==a){
			if(c<=n){
				std::cout<<c;
				break;
			}else if(c<2*n){
				std::cout<<2*n-c+1;
				break;
			}else if(c%n==1){
				cout<<1<<endl;
			}else if(c>2*n){
				if(c-2*n==1){
					std::cout<<n;
					break;
				}else{
					std::cout<<c-2*n+1;
					break;
				}
			}
		}
	}
	return 0;
}
