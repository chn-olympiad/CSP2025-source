#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r=1,ra;
	cin>>n>>m>>ra;
	for(int i=0;i<n*m-1;i++){
		int a;
		cin>>a;
		if(a>ra){
			r++;
		}
	}
	cout<<(r+n-1)/n<<' ';
	if(((r+n-1)/n)%2==1){
		cout<<(r+n-1)%n+1;
	}else{
		cout<<n-(r+n-1)%n;
	}
	return 0;
}
