#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			s++;
		}
	}
	cout<<s<<n;
	cout<<s/n<<" "<<((s/n)%2==1?s%n+1:n-(s%n));
	return 0;
}
