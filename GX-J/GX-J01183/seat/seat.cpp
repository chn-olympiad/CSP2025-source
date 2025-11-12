include<bits/c++.h>
using namespace std;
int main(){
freopen(stdin,"r",seat.in);
freout(stdout,"w",seat.out);
	long long n,m,c,r,f,e;
	long long a[10000000];
	cin>>n>>m;
	for(int i=0;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[0];
	int max=a[0];
	for(int i=0;i<=n*m;i++){
		if(a[i]<max){
			e=a[i];
			a[i]=max;
			max=e;
		}
		else{
		max=a[i];
		}
	}
	for(int i=0;i<=n*m;i++){
		if(f==a[i]){
			e=i+1;
			break;
		}
	}
	r=n-((n*m-e)%n);
	if(r%n!=0){
		c=(r/n)+1;
	}
	else{
		c=r/n;
	}
	cout<<c<<" "<<r;
	return 0;
}
