#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,j;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			j=i;
			break;
		}
	}
	if(j%n==0){
		if(j/n%2==1){
			cout<<j/n<<" "<<m;
		}
		else{
			cout<<j/n<<" "<<1;
		}
	}
	else{
		if((j/n+1)%2==0){
			cout<<j/n+1<<" "<<n-j%n+1;
		}
		else{
			cout<<j/n+1<<" "<<j%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
