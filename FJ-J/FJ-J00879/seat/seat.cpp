#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a[n*m+5];
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int b=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=(n*m)/2;i++){
		int c=a[n*m-i+1];
		a[n*m-i+1]=a[i];
		a[i]=c;
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	if(b%n==0){
		if((b/n)%2==1){
			cout<<b/n<<" "<<n;
		} else{
			cout<<b/n<<" "<<1;
		}
	}else{
		if((b/n+1)%2==1){
			cout<<b/n+1<<" "<<b%n;
		}else{
			cout<<b/n+1<<" "<<n-b%n+1;
		}
	}
	return 0;
} 
