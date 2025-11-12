#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],mx=-100000000,mi=1000000000;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		cout<<min(a[i],mi);
		//cout<<mi<<" ";
		//	if(a[i]>mx){
			//	mx=a[i];
		//		cout<<mx<<" ";
		//		mx=-100000000;
		//	}
		}
	//for(int i=1;i<=n*m;i++){
		
	//}
		
	
	return 0;
}
