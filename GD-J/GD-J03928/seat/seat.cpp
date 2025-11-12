#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1); 
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			int x=(i%n==0?n:i%n);
			if((i-1)/n%2==0){
				cout<<(i-1)/n+1<<" "<<x<<endl; 
			}else{
				cout<<(i-1)/n+1<<" "<<n-x+1<<endl;
			}
			break;
		}
	}
	return 0;
} 
