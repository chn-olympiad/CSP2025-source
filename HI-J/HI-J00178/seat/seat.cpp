#include <bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1],b=0;
	sort(a+1,a+n+1);
	for(int i=0;i<=n*m;i++){
		b+=1;
		if(a[i]==num) break;
		
	}
	
	if(b<=n) cout<<1<<" "<<b;
	if(b>n) {
		cout<<b/n<<" "<<b%n;
	}
			
		
	return 0;
}
