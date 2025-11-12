#include<bits/stdc++.h>
using namespace std;
int n,m,b=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			b++;
		}
	}
	if(b%n==0){
		cout<<b/n<<" ";
		if(b/n%2==0){
			cout<<"1"<<endl;
		}else{
			cout<<n<<endl;
		}
	}else{
		cout<<b/n+1<<" ";
		if(b/n%2==0){
			cout<<b-b/n*n<<endl; 
		}else{
			cout<<n-b+b/n*n<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
