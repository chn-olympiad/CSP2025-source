#include<bits/stdc++.h>
using namespace std;
int s (int x,int y){
	return x>y;
}
int n,m,a[1000],z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	z=a[1];
	sort(a+1,a+n*m,s);
	for(int i=1;i<=n*m;i++){
		if(a[i]==z){
			if(i%n!=0){
				cout<<i/n+1<<" ";
				if((i/n)%2!=0){
					cout<<n-i%n+1;
				}else{
					cout<<i%n;
				}
			}else{
				cout<<i/n<<" ";
				if((i/n)%2==0){
					cout<<"1";
				}else{
					cout<<n;
				}
			}
		}
		
	}
				
	fclose(stdin);
	fclose(stdout);
	return 0;
}
