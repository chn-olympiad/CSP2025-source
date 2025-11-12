#include<bits/stdc++.h>
using namespace std;
long long b[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,id=1;
	cin>>n>>m>>b[1];
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
		if(b[i]>b[1]){
			id++;
		}
	}
	if(id==1){
		cout<<"1"<<" "<<"1";
		return 0;
	}
	cout<<id<<endl;
	if(id%n==0){
		if((id%n)%2==0){
			cout<<"1"<<" "<<n;
		} else {
			cout<<n<<" "<<id/n;
		}
	} else {
		if(id/n%2==0){
			cout<<id%n<<" "<<id/n+1;
		} else {
			cout<<n-id%n+1<<" "<<id/n+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
