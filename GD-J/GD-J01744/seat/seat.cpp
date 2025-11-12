#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,m,a[N],num;
signed main(int argc,char *argv[]){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n>>m;
	for(register int i=1;i<=n*m;i++){
		std::cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1);
	for(register int i=1;i<=n*m;i++){
		if(a[n*m-i+1]==num){
			int cnt;
			if(i%n==0){
				cnt=i/n;
			}else{
				cnt=i/n+1;
			}
			std::cout<<cnt<<" ";
			if(cnt%2==1){
				std::cout<<(i-1)%n+1;
			}else{
				std::cout<<n-(i-1)%n;
			}
//			std::cout<<'\n'<<i;
			break;
	 	}
	}
//	for(register int i=1;i<=n*m;i++){
//		std::cout<<a[i]<<" ";
//	}
	return 0;
}
