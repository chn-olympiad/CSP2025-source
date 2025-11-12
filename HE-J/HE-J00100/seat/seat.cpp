#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,ee=0;
	cin>>n>>m;
	long long num=n*m,s[num];
	for(int i=0;i<num;++i){
		cin>>s[i];
	}
	for(int i=1;i<num;++i){
		if(s[i]>s[0]){
			++ee;
		}
	}
	++ee;
	if(((ee/n)+1)%2==0&&ee%n!=0){
		cout<<(ee/n)+1<<' '<<n+1-(ee%n);
	}else if(ee%n==1){
		cout<<(ee/n)+1<<' '<<ee%n;
	}else{
		cout<<ee/n<<' '<<n-(ee%n);
	}
	return 0;
}

