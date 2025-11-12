#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int n,m,q;
	cin>>n>>m>>q;
	a[1]=q;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+100);
	for(int i=100-n*m;i<=100;i++){
		if(a[i]==q){
			i-=101-n*m;
			if(i/n%2==1){
				cout<<i/n+2<<" "<<11-i%n;
			}else{
				cout<<i/n+2<<" "<<i%n+1;
			}
			return 0;
		}
	} 
}
