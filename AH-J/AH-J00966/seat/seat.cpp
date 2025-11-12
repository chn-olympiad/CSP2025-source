#include<bits/stdc++.h>
using namespace std;
int n,m,s=1;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			s++;
		}
	}
	if(s%n==0){
		cout<<s/n<<' ';
		if((s/n-1)%2==1){
			cout<<1;
		}else{
			cout<<n;
		}
	}else{
		cout<<s/n+1<<' ';
		if((s/n)%2==1){
			cout<<n+1-s%n;
		}else{
			cout<<s%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
