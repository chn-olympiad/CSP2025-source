#include<iostream>
#define ll long long
using std::cin;
using std::cout;
using std::endl;
ll n,m,k;
struct node{
	ll k,id;
}a[1000];
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	a[1].id=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].k;
	}
	
	for(int i=1;i<=n*m;i++){
		for(int j=n*m;j>=2;j--){
			if(a[j].k>a[j-1].k){
				a[j].k+=a[j-1].k;
				a[j-1].k=a[j].k-a[j-1].k;
				a[j].k-=a[j-1].k;
				a[j].id+=a[j-1].id;
				a[j-1].id=a[j].id-a[j-1].id;
				a[j].id-=a[j-1].id;
			}
		}
	}
	
//	cout<<endl;
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].k<<" ";
//	}
	
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			k=i;
			break;
		}
	}//cout<<endl<<k<<endl;
	
	if(k%n==0){
		if((k/n)%2==0)
			cout<<k/n<<" "<<1;
		else
			cout<<k/n<<" "<<n;
		return 0;
	}else{
		int p=k%n;
		k-=p;
		if((k/n)%2==0)
			cout<<k/n+1<<" "<<p;
		else
			cout<<k/n+1<<" "<<n-p+1;
		return 0;
	}
	return 0;
}
/*
4 5
15 20 16 3 9 8 1 7 12 11 19 2 4 5 6 14 10 17 13 18

*/
