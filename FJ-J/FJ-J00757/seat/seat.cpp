#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,a,z=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;++i){
		int l=0;
		cin>>l;
		if(a<l){
			++z;
		}
	}
	cout<<z/n<<' ';
	if(z/n%2==0){
		cout<<m-z%(m+1)+1<<' ';
	}
	else{
		cout<<z%(m+1)<<' ';
	}
	return 0;
} 
