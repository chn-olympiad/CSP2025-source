#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[110],x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;++i){
		cin>>b[i];
	}sort(b+1,b+n);
	for(int i=1;i<n*m;++i){
		if(b[i]<a){
			break;
		}else{
			if(x%2==1){
				++y;
				if(y%n==1){
					++x;
					--y;
				}
			}else{
				--y;
				if(y%n==0){
					++x;
					++y;
				}
			}
		}
	}cout<<x<<" "<<y;
	return 0;
}
